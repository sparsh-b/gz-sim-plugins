# Migrating a plugin from Gazebo-classic to (new) Gazebo
- This file documents my experience migrating a plugin from Gazebo-classic to (new) Gazebo.

## Bunch of Documentation of Migrating away from Gazebo-classic
- Scroll down to the <u>Migration from Gazebo classic</u> section on [this](https://gazebosim.org/api/sim/8/tutorials.html) page.

## Official examples & Tutorials for (the new) Gazebo
- [Example - On creating a plugin](https://github.com/gazebosim/gz-sim/tree/gz-sim8/examples/plugin)
- [Example - Other standalones](https://github.com/gazebosim/gz-sim/tree/gz-sim8/examples/standalone)
- [Tutorial - Gazebo Transport](https://gazebosim.org/api/transport/13/tutorials.html)

## How to search for help on a specific problem on Google
- While Googling, use search terms like `How to xxxxx in Gazebo`_`Ignition`_.
  - Do this even if you are developing for (the new) Gazebo.
  - Because if you just google for `How to xxxxx in Gazebo`, more likely than not, you will land on pages meant for Gazebo-classic.
  - See the next step to know how to use this help meant for Gazebo Ignition for (the new) Gazebo.
- In any code snippets you get from an Ignition Gazebo page:
  - Replace any:
    - `Ignition` with `Gz`
    - `Gazebo` with `Sim`
    - `ign` with `gz`
    - `Ign` with `Gz`
  - Note that Upper-case is maintained wherever exists.
  - For example: Replace `#include <ignition/gazebo/Types.hh>` with `#include <gz/sim/Types.hh>`
  - This should be enough for most things. But, have a look at [this](https://gazebosim.org/docs/harmonic/migration_from_ignition) extensive guide on migration from Ignition to (new) Gazebo.
    - <u>**<h3>Especially look at these [Gotchas!](https://gazebosim.org/docs/harmonic/migration_from_ignition#gotchas)</h3>**</u>

## A Note about Ignition Gazebo (Fortress)
- At the time of writing, the official recommended version of Gazebo for ROS2 Iron is Ignition Gazebo Fortress.
- The compatibility of Iron with Harmonic is mentioned as "Possible but use with Caution" on the Official Gazebo website.
- <img src="./imgs/Gazebo-ROS%20compatibility.png" alt="Gazebo-ROS compatibility" width="300"/>
- However, it looks like a few things are broken in Fortress and it is better to do development in Gazebo Harmonic directly.
  - While developing the `modify_light_plugin` in Fortress, the lights were not working the way they were supposed to.
  - I was able to get around this by just migrating the code base from Fortress to Harmonic and no additional un-bugging.