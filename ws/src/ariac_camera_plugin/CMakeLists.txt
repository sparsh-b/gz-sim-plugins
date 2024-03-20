cmake_minimum_required(VERSION 3.8)
project(ariac_camera_plugin)

# set(THIS_PACKAGE_INCLUDE_DEPENDS

# )

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(gz-cmake3 REQUIRED)
find_package(gz-plugin2 REQUIRED COMPONENTS register)
find_package(gz-sim8 REQUIRED)
set(GZ_PLUGIN_VER ${gz-plugin2_VERSION_MAJOR})


add_library(AriacCameraPlugin SHARED src/ariac_camera_plugin.cpp)
target_include_directories(AriacCameraPlugin PUBLIC include)
# set_property(TARGET AriacCameraPlugin PROPERTY CXX_STANDARD 17)
target_link_libraries(AriacCameraPlugin
  PRIVATE gz-plugin${GZ_PLUGIN_VER}::gz-plugin${GZ_PLUGIN_VER}
  PRIVATE gz-sim8::gz-sim8)
# ament_target_dependencies(AriacCameraPlugin

# )

ament_export_libraries(AriacCameraPlugin)
ament_package()


install(TARGETS
    AriacCameraPlugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)



############################## For a ROS Package ##############################

# cmake_minimum_required(VERSION 3.8)
# project(ariac_camera_plugin)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # find dependencies
# find_package(ament_cmake REQUIRED)

# ament_package()
