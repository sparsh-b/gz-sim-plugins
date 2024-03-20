#include <gz/plugin/Register.hh>

#include "ariac_camera_plugin/ariac_camera_plugin.hpp"

namespace ariac_sensors{
  
  AriacCameraPlugin::AriacCameraPlugin() {gzmsg << "\n\nHello from Constructor!!\n\n";}
  AriacCameraPlugin::~AriacCameraPlugin() {}

  void AriacCameraPlugin::Configure (const gz::sim::Entity &_entity,
                      const std::shared_ptr<const sdf::Element> &_sdf,
                      gz::sim::EntityComponentManager &_ecm,
                      gz::sim::EventManager &) {
                        gzmsg << "\n\nHello from Configure\n\n";
                      }

  void AriacCameraPlugin::PostUpdate (const gz::sim::UpdateInfo &_info,
                       const gz::sim::EntityComponentManager &_ecm) {
                        gzmsg << "\n\nHello from PostUpdate\n\n";
                       }


}

GZ_ADD_PLUGIN(
  ariac_sensors::AriacCameraPlugin,
  gz::sim::System,
  ariac_sensors::AriacCameraPlugin::ISystemConfigure,
  ariac_sensors::AriacCameraPlugin::ISystemPostUpdate
)
