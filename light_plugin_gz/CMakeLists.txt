cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(modify_light)

find_package(gz-cmake3 REQUIRED)
find_package(gz-plugin2 REQUIRED COMPONENTS register)
set(GZ_PLUGIN_VER ${gz-plugin2_VERSION_MAJOR})

find_package(gz-sim8 REQUIRED)

add_library(ModifyLight SHARED src/modify_light_plugin.cpp)
target_include_directories(ModifyLight PUBLIC include)
set_property(TARGET ModifyLight PROPERTY CXX_STANDARD 17)
target_link_libraries(ModifyLight
  PRIVATE gz-plugin${GZ_PLUGIN_VER}::gz-plugin${GZ_PLUGIN_VER}
  PRIVATE gz-sim8::gz-sim8)
