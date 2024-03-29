// Generated by gencpp from file vedio/msg_led.msg
// DO NOT EDIT!


#ifndef VEDIO_MESSAGE_MSG_LED_H
#define VEDIO_MESSAGE_MSG_LED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vedio
{
template <class ContainerAllocator>
struct msg_led_
{
  typedef msg_led_<ContainerAllocator> Type;

  msg_led_()
    : right(0)
    , left(0)  {
    }
  msg_led_(const ContainerAllocator& _alloc)
    : right(0)
    , left(0)  {
  (void)_alloc;
    }



   typedef uint8_t _right_type;
  _right_type right;

   typedef uint8_t _left_type;
  _left_type left;




  typedef boost::shared_ptr< ::vedio::msg_led_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vedio::msg_led_<ContainerAllocator> const> ConstPtr;

}; // struct msg_led_

typedef ::vedio::msg_led_<std::allocator<void> > msg_led;

typedef boost::shared_ptr< ::vedio::msg_led > msg_ledPtr;
typedef boost::shared_ptr< ::vedio::msg_led const> msg_ledConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vedio::msg_led_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vedio::msg_led_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vedio

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'vedio': ['/home/ubuntu/catkin_ws/src/vedio/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vedio::msg_led_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vedio::msg_led_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vedio::msg_led_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vedio::msg_led_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vedio::msg_led_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vedio::msg_led_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vedio::msg_led_<ContainerAllocator> >
{
  static const char* value()
  {
    return "078c84f9568e7559c51e2f26d02eed38";
  }

  static const char* value(const ::vedio::msg_led_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x078c84f9568e7559ULL;
  static const uint64_t static_value2 = 0xc51e2f26d02eed38ULL;
};

template<class ContainerAllocator>
struct DataType< ::vedio::msg_led_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vedio/msg_led";
  }

  static const char* value(const ::vedio::msg_led_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vedio::msg_led_<ContainerAllocator> >
{
  static const char* value()
  {
    return "char right\n\
char left\n\
";
  }

  static const char* value(const ::vedio::msg_led_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vedio::msg_led_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.right);
      stream.next(m.left);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct msg_led_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vedio::msg_led_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vedio::msg_led_<ContainerAllocator>& v)
  {
    s << indent << "right: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.right);
    s << indent << "left: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.left);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VEDIO_MESSAGE_MSG_LED_H
