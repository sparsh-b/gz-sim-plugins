#ifndef ARIAC_CAMERA_PLUGIN_HPP
#define ARIAC_CAMERA_PLUGIN_HPP

// #include <rclcpp/rclcpp.hpp>

#include <gz/sim/System.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/EventManager.hh>
#include <gz/sim/components/Component.hh>
#include <gz/sim/components/Name.hh>
#include <gz/sim/Sensor.hh>


#include <gz/rendering/Camera.hh>
#include <gz/sensors/CameraSensor.hh>
#include <gz/sensors/Manager.hh>

#include <gz/transport/Node.hh>

namespace ariac_sensors{
  class AriacCameraPlugin : 
    public gz::sim::System,
    public gz::sim::ISystemConfigure
    // public gz::sim::ISystemPostUpdate
  {
    public:
      AriacCameraPlugin();
      ~AriacCameraPlugin();

      void Configure (const gz::sim::Entity &_entity,
                      const std::shared_ptr<const sdf::Element> &_sdf,
                      gz::sim::EntityComponentManager &_ecm,
                      gz::sim::EventManager &_event_mgr) override;

      void OnNewImageFrame(const unsigned char *_image,
                  unsigned int _width, unsigned int _height,
                  unsigned int _depth, const std::string &_format);
      
      // void PostUpdate (const gz::sim::UpdateInfo &_info,
      //                  const gz::sim::EntityComponentManager &_ecm) override;
    
    private:
      std::shared_ptr<gz::transport::Node> gz_node_;
      // rclcpp::Node::SharedPtr ros_node_;
      gz::rendering::CameraPtr camera_;
      // gz::common::ConnectionPtr newImageFrameConnection_;
      std::shared_ptr<gz::sensors::CameraSensor> camera_parent_sensor_;
      
  };
}

#endif