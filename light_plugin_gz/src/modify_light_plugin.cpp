#include "light_plugin_gz/modify_light_plugin.hpp"
#include <gz/plugin/Register.hh>
#include <gz/sim/Types.hh>



// this->dataPtr->intensities = {0.23, 0.65, 0.2, 0.5, 0.25, 0.29, 0.63, 0.21, 0.19, 0.29, 0.74, 0.32, 0.2, 0.39, 0.23, 0.45, 0.21, 0.5, 0.28, 0.81, 0.32, 0.21, 0.61, 0.22, 0.84, 0.29, 0.51, 0.19, 0.67, 0.24, 0.67, 0.22, 0.58, 0.27, 0.44, 0.56, 0.28, 0.6, 0.21, 0.48, 0.43, 0.37, 0.37, 0.18, 0.76, 0.27, 0.28, 0.23, 0.9, 0.32, 0.32, 0.34, 0.55, 0.55, 0.86, 0.31, 0.43, 0.81, 0.33, 0.33, 0.22, 0.8, 0.27, 0.75, 0.31, 0.19, 0.59, 0.22, 0.59, 0.41, 0.25, 0.88, 0.29, 0.41, 0.42, 0.8, 0.48, 0.33, 0.82, 0.31, 0.39, 0.5, 0.36, 0.52, 0.86, 0.47, 0.51, 0.87, 0.4, 0.96, 0.96, 0.22, 0.63, 0.2, 0.61, 0.3, 0.83, 0.31, 0.33, 0.33, 0.6, 0.38, 0.68, 0.29, 0.59, 0.35, 0.53, 0.44, 0.25, 0.81, 0.32, 0.41, 0.57, 0.28, 1.0, 0.39, 0.32, 0.72, 0.28, 0.77, 0.38, 0.53, 0.7, 0.34, 0.59, 0.23, 0.54, 0.22, 0.55, 0.21, 0.54, 0.21, 0.61, 0.23, 0.52, 0.37, 0.21, 0.62, 0.33, 0.46, 0.22, 0.51, 0.67, 0.41, 0.23, 0.56, 0.24, 0.75, 0.28, 0.59, 0.35, 0.43, 0.53, 0.32, 0.96, 0.42, 0.46, 0.57, 0.4, 0.62, 0.38, 0.68, 0.38, 0.9, 0.42, 0.94, 0.4, 0.36, 0.58, 0.67, 0.6, 0.36, 0.78, 0.49, 0.5, 0.64, 0.53, 0.35, 0.92, 0.38, 0.45, 0.45, 0.81, 0.5, 0.37, 0.71, 0.43, 0.56, 0.86, 0.37, 0.34, 0.4, 0.75, 0.39, 0.26, 0.72, 0.27, 0.96, 0.35, 0.81, 0.3, 0.51, 0.24, 0.83, 0.3, 0.2, 0.46, 0.52, 0.26, 0.61, 0.17, 0.56, 0.15, 0.15, 0.56, 0.3, 0.31, 0.15, 0.48, 0.26, 0.27, 0.48, 0.19, 0.57, 0.1, 0.34, 0.44, 0.36, 0.18, 0.62, 0.19, 0.23, 0.31, 0.31, 0.24, 0.3, 0.44, 0.19, 0.78, 0.3, 0.79, 0.31, 0.2, 0.45, 0.58, 0.35};


GZ_ADD_PLUGIN(
    modify_light_plugin::ModifyLightPlugin,
    gz::sim::System,
    // modify_light_plugin::ModifyLightPlugin::ISystemConfigure,
    modify_light_plugin::ModifyLightPlugin::ISystemPreUpdate
)

using namespace modify_light_plugin;
using namespace std::chrono_literals;

ModifyLightPlugin::ModifyLightPlugin() 
{
    // this->light_intensity = 1.0;
    this->iteration = 0;
    this->intensities = {0.23, 0.65, 0.2, 0.5, 0.25, 0.29, 0.63, 0.21, 0.19, 0.29, 0.74, 0.32, 0.2, 0.39, 0.23, 0.45, 0.21, 0.5, 0.28, 0.81, 0.32, 0.21, 0.61, 0.22, 0.84, 0.29, 0.51, 0.19, 0.67, 0.24, 0.67, 0.22, 0.58, 0.27, 0.44, 0.56, 0.28, 0.6, 0.21, 0.48, 0.43, 0.37, 0.37, 0.18, 0.76, 0.27, 0.28, 0.23, 0.9, 0.32, 0.32, 0.34, 0.55, 0.55, 0.86, 0.31, 0.43, 0.81, 0.33, 0.33, 0.22, 0.8, 0.27, 0.75, 0.31, 0.19, 0.59, 0.22, 0.59, 0.41, 0.25, 0.88, 0.29, 0.41, 0.42, 0.8, 0.48, 0.33, 0.82, 0.31, 0.39, 0.5, 0.36, 0.52, 0.86, 0.47, 0.51, 0.87, 0.4, 0.96, 0.96, 0.22, 0.63, 0.2, 0.61, 0.3, 0.83, 0.31, 0.33, 0.33, 0.6, 0.38, 0.68, 0.29, 0.59, 0.35, 0.53, 0.44, 0.25, 0.81, 0.32, 0.41, 0.57, 0.28, 1.0, 0.39, 0.32, 0.72, 0.28, 0.77, 0.38, 0.53, 0.7, 0.34, 0.59, 0.23, 0.54, 0.22, 0.55, 0.21, 0.54, 0.21, 0.61, 0.23, 0.52, 0.37, 0.21, 0.62, 0.33, 0.46, 0.22, 0.51, 0.67, 0.41, 0.23, 0.56, 0.24, 0.75, 0.28, 0.59, 0.35, 0.43, 0.53, 0.32, 0.96, 0.42, 0.46, 0.57, 0.4, 0.62, 0.38, 0.68, 0.38, 0.9, 0.42, 0.94, 0.4, 0.36, 0.58, 0.67, 0.6, 0.36, 0.78, 0.49, 0.5, 0.64, 0.53, 0.35, 0.92, 0.38, 0.45, 0.45, 0.81, 0.5, 0.37, 0.71, 0.43, 0.56, 0.86, 0.37, 0.34, 0.4, 0.75, 0.39, 0.26, 0.72, 0.27, 0.96, 0.35, 0.81, 0.3, 0.51, 0.24, 0.83, 0.3, 0.2, 0.46, 0.52, 0.26, 0.61, 0.17, 0.56, 0.15, 0.15, 0.56, 0.3, 0.31, 0.15, 0.48, 0.26, 0.27, 0.48, 0.19, 0.57, 0.1, 0.34, 0.44, 0.36, 0.18, 0.62, 0.19, 0.23, 0.31, 0.31, 0.24, 0.3, 0.44, 0.19, 0.78, 0.3, 0.79, 0.31, 0.2, 0.45, 0.58, 0.35};
    this->directionX = 0.5;
    this->directionY = 0.2;
    this->directionZ = -0.9;
    
    this->lightRequest.set_name("light1");
    this->lightRequest.set_range(1000);
    this->lightRequest.set_attenuation_linear(0.01);
    this->lightRequest.set_attenuation_constant(0.9);
    this->lightRequest.set_attenuation_quadratic(0.001);
    this->lightRequest.set_cast_shadows(true);
    this->lightRequest.set_intensity(2);
    this->lightRequest.set_type(gz::msgs::Light::POINT);
    // direction field only affects spot / directional lights
    gz::msgs::Set(this->lightRequest.mutable_direction(),
      gz::math::Vector3d(this->directionX, this->directionY, this->directionZ));
    gz::msgs::Set(this->lightRequest.mutable_pose(),
      gz::math::Pose3d(0.0, 0, 2, 0.0, 0.0, 0.0));

    gzmsg << "Plugin Constructor executed!";
    // this->twister = std::time(0);
    // std::uniform_real_distribution<double> distr(0, 1000);
    // this->epsilon = 0.1;
}

ModifyLightPlugin::~ModifyLightPlugin() 
{

}

// void Configure(const gz::sim::Entity &_entity, const std::shared_ptr<const sdf::Element> &_sdf,
//                 gz::sim::EntityComponentManager &_ecm, gz::sim::EventManager &_eventMgr) 
// {
//     gzmsg << "\n\nInside Configure\n\n";
// }

void ModifyLightPlugin::PreUpdate(const gz::sim::UpdateInfo &_info, 
    gz::sim::EntityComponentManager &_ecm)
{
    this->iteration++;
    if (this->iteration >= this->intensities.size())
      this->iteration = 0;

    auto color = gz::math::Color(this->intensities[this->iteration], this->intensities[this->iteration], 
        this->intensities[this->iteration], 1);

    
    // std::mt19937 twister(std::time(0));
    // std::uniform_real_distribution<double> distr(0, 1000);
    // constexpr double epsilon = 0.1;

    // float r, g, b;
    // double m = 0;
    // //! [random numbers]
    // while (m < epsilon)
    // {
    //   r = distr(twister);
    //   g = distr(twister);
    //   b = distr(twister);
    //   m = std::sqrt(r*r + b*b + g*g);
    // }

    // r /= m;
    // g /= m;
    // b /= m;

    

    //! [modify light]
    // lightRequest.set_range(100);
    // lightRequest.set_attenuation_linear(0.01);
    // lightRequest.set_attenuation_constant(0.9);
    // lightRequest.set_attenuation_quadratic(0.001);
    // lightRequest.set_cast_shadows(true);
    // lightRequest.set_type(gz::msgs::Light::POINT);
    // lightRequest.set_spot_inner_angle(0.1);
    // lightRequest.set_spot_outer_angle(0.5);
    // lightRequest.set_spot_falloff(0.80000000000000004);
    // gz::msgs::Set(lightRequest.mutable_direction(),
    //     gz::math::Vector3d(0, 0, -1));
    // gz::msgs::Set(lightRequest.mutable_pose(),
    //     gz::math::Pose3d(0.0, 0.0, 2.0, 0.0, 0.0, 0.0));
    // gz::msgs::Set(lightRequest.mutable_diffuse(), color);
    // gz::msgs::Set(lightRequest.mutable_specular(), color);
    
    gz::msgs::Set(this->lightRequest.mutable_diffuse(), color);
    gz::msgs::Set(this->lightRequest.mutable_specular(), color);
    //! [modify light]

    this->executed = this->node.Request(this->lightConfigService, this->lightRequest, this->timeout,\
     this->response, this->result);
    std::cout << "Service called" << std::endl;

    if (this->executed)
    {
      if (this->result)
        std::cout << "Response: [" << this->response.data() << "]" << std::endl;
      else
        std::cout << "Service call failed" << std::endl;
    }
    else
      std::cerr << "Service call timed out" << std::endl;

    std::this_thread::sleep_for(100ms);

}
