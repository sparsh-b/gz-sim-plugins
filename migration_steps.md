# Migrating a plugin from Gazebo-classic to (new) Gazebo
- This file documents my experience migrating a plugin from Gazebo-classic to (new) Gazebo.

## How to search for help on Google
- While Googling, use search terms like `How to xxxxx in Gazebo Ignition`.
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