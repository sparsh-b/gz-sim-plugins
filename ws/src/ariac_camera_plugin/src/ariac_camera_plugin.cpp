#include <gz/plugin/Register.hh>
#include <typeinfo>


#include "ariac_camera_plugin/ariac_camera_plugin.hpp"

namespace ariac_sensors{
  
  AriacCameraPlugin::AriacCameraPlugin() {gzmsg << "\n\nHello from Constructor!!\n\n";
    // ROS node
    // this->ros_node_ = rclcpp::Node::make_shared("ros_gz_ariac_camera");
    // this->ros_node_->declare_parameter("qos", "default");

    // Gazebo node
    this->gz_node_ = std::make_shared<gz::transport::Node>();

  }
  AriacCameraPlugin::~AriacCameraPlugin() {}

  void AriacCameraPlugin::Configure (const gz::sim::Entity &_entity,
                      const std::shared_ptr<const sdf::Element> &_sdf,
                      gz::sim::EntityComponentManager &_ecm,
                      gz::sim::EventManager &_event_mgr) {
    
    gzmsg << "\n\nHello from Configure\n\n";

    auto entities = _ecm.EntitiesByComponents(gz::sim::components::Name("rgb_camera")
                                            // , gz::sim::components::Camera()
                                              );
    gzmsg << entities.size() << "\n";
    // std::cout << typeid(entities[0]).name() << '\n';
    std::cout << std::to_string(entities[0]) << '\n';

    gz::sim::Sensor sensor = gz::sim::Sensor(entities[0]);
    if (sensor.Topic(_ecm).has_value()) {
      gzmsg << sensor.Topic(_ecm).value() << std::endl;
    } else {
      gzmsg << "No Value\n";
    }

    std::cout << sensor.Valid(_ecm);

    // auto manager = gz::sensors::Manager();
    // gz::sensors::Sensor *sensor_ptr = manager.Sensor(entities[0]);
    // auto is_active = sensor_ptr->IsActive();

    // std::shared_ptr<gz::sensors::Sensor> sensor_shared_ptr(sensor_ptr);

    // std::shared_ptr<gz::sensors::CameraSensor> cam_shared_ptr = 
    //   std::dynamic_pointer_cast<gz::sensors::CameraSensor>(sensor_shared_ptr);

    // gz::sensors::CameraSensor *cam_sensor_ptr = 
    //   std::dynamic_pointer_cast<gz::sensors::CameraSensor*>(sensor_ptr);

    // // auto s_ptr = std::make_shared<gz::sensors::CameraSensor>();//sensor_ptr);
    // std::shared_ptr<gz::sensors::CameraSensor> cam_shared_ptr(cam_sensor_ptr);
    // this->camera_ = cam_shared_ptr->RenderingCamera();

    // auto is_active = sensor_shared_ptr->IsActive();
    // std::cout << topic_name+"\n";
    // this->camera_parent_sensor_ = std::dynamic_pointer_cast<gz::sensors::CameraSensorPtr>(_sensor);
    // this->camera_parent_sensor_ = std::make_shared<gz::sensors::CameraSensor>(_entity);//entities[0]);
    // this->camera_ = this->camera_parent_sensor_->RenderingCamera();

    // this->newImageFrameConnection_ = this->camera_->ConnectNewImageFrame(
    //   std::bind(&AriacCameraPlugin::OnNewImageFrame, this,
    //     std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
    //     std::placeholders::_4, std::placeholders::_5)
    // );
  }

  // void AriacCameraPlugin::PostUpdate (const gz::sim::UpdateInfo &_info,
  //                      const gz::sim::EntityComponentManager &_ecm) {
  //                       // gzmsg << "\n\nHello from PostUpdate\n\n";
  //                      }


}

GZ_ADD_PLUGIN(
  ariac_sensors::AriacCameraPlugin,
  gz::sim::System,
  ariac_sensors::AriacCameraPlugin::ISystemConfigure
  // ariac_sensors::AriacCameraPlugin::ISystemPostUpdate
)
