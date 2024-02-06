# Light Plugin in Gazebo Harmonic
- This repository holds a running implementation of a Gazebo Harmonic plugin to modify a light source.

# Environment
- This repository is tested on a docker container running ROS2 Iron + Gazebo Harmonic

# Steps to Run
## Build the plugin
- `mkdir build && cd build`
- `cmake .. && make`
- Specify the path of plugin library file using `export GZ_SIM_SYSTEM_PLUGIN_PATH=<path-to-.so-file>`
