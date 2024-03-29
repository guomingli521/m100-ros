// Generated by gencpp from file dji_sdk/WaypointList.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_WAYPOINTLIST_H
#define DJI_SDK_MESSAGE_WAYPOINTLIST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <dji_sdk/Waypoint.h>

namespace dji_sdk
{
template <class ContainerAllocator>
struct WaypointList_
{
  typedef WaypointList_<ContainerAllocator> Type;

  WaypointList_()
    : waypoint_list()  {
    }
  WaypointList_(const ContainerAllocator& _alloc)
    : waypoint_list(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::dji_sdk::Waypoint_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::dji_sdk::Waypoint_<ContainerAllocator> >::other >  _waypoint_list_type;
  _waypoint_list_type waypoint_list;




  typedef boost::shared_ptr< ::dji_sdk::WaypointList_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::WaypointList_<ContainerAllocator> const> ConstPtr;

}; // struct WaypointList_

typedef ::dji_sdk::WaypointList_<std::allocator<void> > WaypointList;

typedef boost::shared_ptr< ::dji_sdk::WaypointList > WaypointListPtr;
typedef boost::shared_ptr< ::dji_sdk::WaypointList const> WaypointListConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::WaypointList_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::WaypointList_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/ubuntu/catkin_ws/src/dji_sdk/msg', '/home/ubuntu/catkin_ws/devel/share/dji_sdk/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::WaypointList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::WaypointList_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::WaypointList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::WaypointList_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::WaypointList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::WaypointList_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::WaypointList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "284386e6fe0f355bdea1db93ead90084";
  }

  static const char* value(const ::dji_sdk::WaypointList_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x284386e6fe0f355bULL;
  static const uint64_t static_value2 = 0xdea1db93ead90084ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::WaypointList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/WaypointList";
  }

  static const char* value(const ::dji_sdk::WaypointList_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::WaypointList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Waypoint[] waypoint_list\n\
\n\
================================================================================\n\
MSG: dji_sdk/Waypoint\n\
#latitude is in degree\n\
float64 latitude\n\
#longitude is in degree\n\
float64 longitude\n\
float32 altitude\n\
#heading is in [-180,180]\n\
int16 heading \n\
#stay time is in second\n\
uint16 staytime\n\
";
  }

  static const char* value(const ::dji_sdk::WaypointList_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::WaypointList_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.waypoint_list);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WaypointList_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::WaypointList_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::WaypointList_<ContainerAllocator>& v)
  {
    s << indent << "waypoint_list[]" << std::endl;
    for (size_t i = 0; i < v.waypoint_list.size(); ++i)
    {
      s << indent << "  waypoint_list[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::dji_sdk::Waypoint_<ContainerAllocator> >::stream(s, indent + "    ", v.waypoint_list[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_WAYPOINTLIST_H
