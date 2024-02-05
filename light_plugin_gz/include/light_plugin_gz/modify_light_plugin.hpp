#ifndef Modify_Light_Plugin_HPP
#define Modify_Light_Plugin_HPP

#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include <gz/sim/System.hh>
#include <gz/transport/Node.hh>


#include <gz/msgs/boolean.pb.h>
#include <gz/msgs/entity_factory.pb.h>
#include <gz/msgs/light.pb.h>
#include <gz/sim/components/Light.hh>
#include <gz/sim/components/LightCmd.hh>
#include <gz/msgs/Utility.hh>

namespace modify_light_plugin {
    class ModifyLightPlugin:
        public gz::sim::System, 
        // public gz::sim::ISystemConfigure,
        public gz::sim::ISystemPreUpdate
    {
        public:
            ModifyLightPlugin();
            ~ModifyLightPlugin() override;

            // void Configure(const gz::sim::Entity &_entity, const std::shared_ptr<const sdf::Element> &_sdf,
            //     gz::sim::EntityComponentManager &_ecm, gz::sim::EventManager &_eventMgr) override;
            void PreUpdate(const gz::sim::UpdateInfo &_info, gz::sim::EntityComponentManager &_ecm) override;

        private:
            float light_intensity;
            gz::transport::Node node;
            int iteration;
            std::vector<float> intensities;
            bool executed;

            // timeout used for services
            unsigned int timeout = 5000;
            float directionX, directionY, directionZ;
            bool result;
            gz::msgs::Boolean response;
            gz::msgs::Light lightRequest;
            const std::string lightConfigService = "/world/sphere_light_world/light_config";
            // TODO: read world's name automatically from the sdf file
    };
}


#endif