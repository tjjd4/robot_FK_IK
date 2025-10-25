

# robot_FK_IK

This repository contains a small C++ example project demonstrating forward and inverse kinematics (FK/IK).

## Supported / Recommended Environment

- Tested / Recommended: Ubuntu 22.04 LTS
- C++ standard: C++17
- Recommended CMake: >= 3.22
- Recommended compiler: GCC >= 11

Notes: If your distribution provides older toolchain versions, consider installing a newer CMake from the official kitware repo or using a newer compiler toolchain.

## Required Packages (Ubuntu / Debian)

Install the following packages on Ubuntu/Debian to build the project:

```bash
sudo apt update
sudo apt install -y build-essential cmake ninja-build libeigen3-dev
```

- `build-essential`: core build tools (gcc/g++, make, etc.)
- `cmake`: build system generator
- `ninja-build`: optional, recommended for faster builds (you can use the default Unix Makefiles instead)
- `libeigen3-dev`: Eigen linear algebra library (C++ header-only)

## Build Instructions

Make sure you are in the repository root (where `CMakeLists.txt` is located).

Run `build.sh` - using CMake with Ninja (recommended):

```bash
./build.sh
```

After building, the compiled binary (if present) will be in the `build` directory (for example `build/main`).