#include"function.h"




typedef struct        //定义圆的中心和半径属性
{
Point2f center;
float rad;
}circleinfodef;

Point2f xy;          //定义画幅中心坐标
//Point2f pot; 	     //用于存放最终输出结果



float LENGTH;

Mat gpulast,test; 
Mat element1=getStructuringElement(MORPH_RECT,Size(3,3));  
Mat element=getStructuringElement(MORPH_RECT,Size(7,7));                       //定义膨胀大小
GpuMat HSV;                                                              //gpu相关的定义
GpuMat HUE,SATURATION,VALUE;
GpuMat HUEH,HUEL,VALUEH,VALUEL,SATURATIONL,SATURATIONH,HSVMID,HSVFINAL,FINAL,ERODE;

const int stateNum=6;    
const int measureNum=2; 
KalmanFilter KF(stateNum, measureNum, 0);
Mat state (stateNum, 1, CV_32FC1); //state(x,y,detaX,detaY)  
Mat processNoise(stateNum, 1, CV_32F);  
Mat measurement = Mat::zeros(measureNum, 1, CV_32F);        //定义初始测量值
float t=0.8;


int limit=10;
 

struct OUTPUT attack_vedio(GpuMat input,vediohit parameter)
{ 
Point2f pot;

 const int64 start = getTickCount();

OUTPUT attack_output;

xy.x=240-80;   //305
xy.y=240+20;   //165









 	gpu::cvtColor(input, HSV, COLOR_BGR2HSV);										   //bgr转hsv
            
 	vector<GpuMat>channels; 
 	gpu::split(HSV,channels);	                                //分离三通道							  							
 	HUE=channels.at(0);
 	SATURATION=channels.at(1);
	VALUE=channels.at(2);
          
 	gpu::threshold(HUE,HUEH,parameter.hith,255,1); //125                   阈值分割取交集 
 	gpu::threshold(HUE,HUEL,parameter.hitl,255,0); //100
 	gpu::bitwise_and(HUEL,HUEH,HUE);
 	gpu::threshold(VALUE,VALUEH,200,255,1);
 	gpu::threshold(VALUE,VALUEL,100,255,0);                 //100
 	gpu::bitwise_and(VALUEL,VALUEH,VALUE);
 	gpu::threshold(SATURATION,SATURATIONH,255,255,1);   //255
 	gpu::threshold(SATURATION,SATURATIONL,250,255,0);   //250
 	gpu::bitwise_and(SATURATIONL,SATURATIONH,SATURATION);
         
 	gpu::bitwise_and(HUE,VALUE,HSVMID);      
 	gpu::bitwise_and(SATURATION,HSVMID,HSVFINAL);

	//gpu::erode(HSVFINAL,ERODE,element1,Point(-1,-1),1);     
 	gpu::dilate(HSVFINAL,FINAL,element,Point(-1,-1),1);        //膨胀
 	input.download(test);                                      //gpu下载
 	FINAL.download(gpulast);

	//imshow("gpulast",gpulast);

 	Mat mincircles(480,480,CV_8UC3);
           
 	vector<vector<Point> > contours;
        findContours(gpulast,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE,Point(0,0));

	vector<circleinfodef> circleinfo;
	vector<circleinfodef> circleinfotemp;

	for(int i=0;i<contours.size();i++)
	{
	 circleinfodef info;
	 minEnclosingCircle(contours[i],info.center,info.rad);                    //最小外接圆
	 int l=arcLength(contours[i],true);
	 	if(l>10 && l<80) //60                                                        //限制轮廓周长
		{
		 circleinfo.push_back(info);
		 circle(mincircles,info.center,info.rad,Scalar(255,255,255),2, 8);         
		}

	int circleSize=circleinfo.size();
	bool flag=false;
		if(circleSize==0)                                                          //画幅内无轮廓，目标点归中
		{
		 pot.x=0;
		 pot.y=0;
		 attack_output.led=01;
		}
  while(circleSize)                                                          //画幅内有轮廓处理
  {
 	 vector<circleinfodef> temp;                                               //存放满足密集度的轮廓
	 vector<circleinfodef> *refcircle;                                         //待处理的轮廓
 		if(flag==false)
  		{
  		 refcircle=&circleinfo;
    		 circleinfotemp.clear();
 		}
    		else
    		{
     		 refcircle=&circleinfotemp;
    		 circleinfo.clear();	
    		}
 	temp.push_back((*refcircle)[0]);
		for(int i=0;i<circleSize-1;i++)
    		{
     		 Point2f line=temp[0].center-(*refcircle)[i+1].center;
     		 float length=sqrtf(line.dot(line));
       			if(length<80)                                                       //两轮廓间的距离限制，判断密集程度  80
        		{
        		 temp.push_back((*refcircle)[i+1]);	
        		}
        		else
        		{
  	        	 	if(flag==false)
    				{
            			 circleinfotemp.push_back((*refcircle)[i+1]);			
    				}
    				else
    				{
             			 circleinfo.push_back((*refcircle)[i+1]);
				}
		    	}             
 		}
               
	Point2f sum;                   	      //定义求和变量---寻找temp中心坐标
	sum.x=0;
	sum.y=0;
	Point2f line;                         //定义temp中心坐标与画幅中心的偏差
	line.x=0;
	line.y=0;

	if(temp.size()>2&temp.size()<10)
	{
  		for(int i=0;i<temp.size();i++)      //寻找temp中心坐标
  		{
   		 sum=sum+temp[i].center;
  		}                
  	
	sum.x=sum.x/temp.size();
  	sum.y=sum.y/temp.size();
  	line=sum-xy;

	float length=sqrtf(line.dot(line));
		if(length<LENGTH)                     //寻找离圆心最近的偏差---pot
		{
 		 LENGTH=length;
 		 pot=line;
		}
	}

	if(flag==false)
	{	
	 circleSize=circleinfotemp.size();
	}
	else
	{
	 circleSize=circleinfo.size();	
	}
	flag=!flag;	
  }
	LENGTH=480;                               //定义距离圆心的最大距离
 	imshow("circle",mincircles);
  	 waitKey(1);

    	attack_output.led=2;  //10
 }   
	Point2f LINE=pot+xy;


	Point statePt = Point( (int)KF.statePost.at<float>(0), (int)KF.statePost.at<float>(1));  
	Mat prediction = KF.predict();
	Point predictPt = Point( (int)prediction.at<float>(0), (int)prediction.at<float>(1));

	measurement.at<float>(0)= (float)LINE.x;  
	measurement.at<float>(1) = (float)LINE.y; 
	
	KF.correct(measurement);  

	Point2f last;
	last.x=LINE.x+prediction.at<float>(2)*t+0.5*prediction.at<float>(4)*t*t;
	last.y=LINE.y+prediction.at<float>(3)*t+0.5*prediction.at<float>(5)*t*t;
	//last.x=LINE.x+prediction.at<float>(2)*t;
	//last.y=LINE.y+prediction.at<float>(3)*t;
	//last.x=prediction.at<float>(0)+prediction.at<float>(2)*t+0.5*prediction.at<float>(4)*t*t;
	//last.y=prediction.at<float>(1)+prediction.at<float>(3)*t+0.5*prediction.at<float>(5)*t*t;

	if(last.x>480||last.x<0||last.y>480||last.y<0)
	{
	 last.x=xy.x;
	 last.y=xy.y;
	}

	circle(test,xy,20,Scalar(0,0,255),2,8);
	circle(test,last,3,Scalar(0,255,0),2,8); 
	circle(test,LINE,3,Scalar(255,255,255),2,8); //绘制目标点
   
	imshow("final",test);
	waitKey(1);

	Point2f aim;
        aim.x=last.x-xy.x;
	aim.y=last.y-xy.y;
    
	if(aim.x<limit&&aim.x>-limit&&aim.y<limit&&aim.y>-limit&&aim.x!=0&&aim.y!=0&&pot.x!=0&&pot.y!=0)
	{			 	
         attack_output.hit=00; 	 		 
	}
	else
	{
	 attack_output.hit=01; 
	}	

	attack_output.xy=pot;
	
const double timeSec = (getTickCount() - start) / getTickFrequency();
// cout << "Time : " << timeSec * 1000 << " ms" << endl;
return 	attack_output;

}


