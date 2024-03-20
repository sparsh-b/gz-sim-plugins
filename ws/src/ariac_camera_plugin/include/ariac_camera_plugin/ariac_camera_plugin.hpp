#ifndef ARIAC_CAMERA_PLUGIN_HPP
#define ARIAC_CAMERA_PLUGIN_HPP

#include <gz/sim/System.hh>
#include <gz/sim/EntityComponentManager.hh>

namespace ariac_sensors{
  class AriacCameraPlugin : 
    public gz::sim::System,
    public gz::sim::ISystemConfigure,
    public gz::sim::ISystemPostUpdate
  {
    public:
      AriacCameraPlugin();
      ~AriacCameraPlugin();

      void Configure (const gz::sim::Entity &_entity,
                      const std::shared_ptr<const sdf::Element> &_sdf,
                      gz::sim::EntityComponentManager &_ecm,
                      gz::sim::EventManager &) override;

      void PostUpdate (const gz::sim::UpdateInfo &_info,
                       const gz::sim::EntityComponentManager &_ecm) override;
      
  };
}

#endif