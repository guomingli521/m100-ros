// Generated by gencpp from file vedio/msg_bomb.msg
// DO NOT EDIT!


#ifndef VEDIO_MESSAGE_MSG_BOMB_H
#define VEDIO_MESSAGE_MSG_BOMB_H


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
struct msg_bomb_
{
  typedef msg_bomb_<ContainerAllocator> Type;

  msg_bomb_()
    : hit(0)  {
    }
  msg_bomb_(const ContainerAllocator& _alloc)
    : hit(0)  {
  (void)_alloc;
    }



   typedef uint8_t _hit_type;
  _hit_type hit;




  typedef boost::shared_ptr< ::vedio::msg_bomb_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vedio::msg_bomb_<ContainerAllocator> const> ConstPtr;

}; // struct msg_bomb_

typedef ::vedio::msg_bomb_<std::allocator<void> > msg_bomb;

typedef boost::shared_ptr< ::vedio::msg_bomb > msg_bombPtr;
typedef boost::shared_ptr< ::vedio::msg_bomb const> msg_bombConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vedio::msg_bomb_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vedio::msg_bomb_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::vedio::msg_bomb_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vedio::msg_bomb_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vedio::msg_bomb_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vedio::msg_bomb_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vedio::msg_bomb_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vedio::msg_bomb_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vedio::msg_bomb_<ContainerAllocator> >
{
  static const char* value()
  {
    return "769aaac581ab49dcf02c605bee12ba0a";
  }

  static const char* value(const ::vedio::msg_bomb_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x769aaac581ab49dcULL;
  static const uint64_t static_value2 = 0xf02c605bee12ba0aULL;
};

template<class ContainerAllocator>
struct DataType< ::vedio::msg_bomb_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vedio/msg_bomb";
  }

  static const char* value(const ::vedio::msg_bomb_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vedio::msg_bomb_<ContainerAllocator> >
{
  static const char* value()
  {
    return "char hit\n\
";
  }

  static const char* value(const ::vedio::msg_bomb_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vedio::msg_bomb_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.hit);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct msg_bomb_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vedio::msg_bomb_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vedio::msg_bomb_<ContainerAllocator>& v)
  {
    s << indent << "hit: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.hit);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VEDIO_MESSAGE_MSG_BOMB_H
