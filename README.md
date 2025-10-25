

# robot_FK_IK

This repository contains a small C++ example project demonstrating forward and inverse kinematics (FK/IK).

## Supported / Recommended Environment

- Tested / Recommended: Ubuntu 22.04 LTS
- C++ standard: C++17
- Recommended CMake: >= 3.22
- Recommended compiler: GCC >= 11

Notes: If your distribution provides older toolchain versions, consider installing a newer CMake from the official kitware repo or using a newer compiler toolchain.

## Install Required Packages (Ubuntu / Debian)

Install the following packages on Ubuntu/Debian to build the project:

```bash
sudo apt update
sudo apt install -y build-essential cmake ninja-build libeigen3-dev
```

- `build-essential`: core build tools (gcc/g++, make, etc.)
- `cmake`: build system generator
- `ninja-build`: optional, recommended for faster builds (you can use the default Unix Makefiles instead)
- `libeigen3-dev`: Eigen linear algebra library (C++ header-only)


### Install robotpkg packages (robotpkg-pinocchio)

Certain robotics packages are not included in the distribution's default package sources. Follow the robotpkg repository setup instructions below to register the robotpkg APT repository and install the required robotpkg- packages (they are installed under /opt/openrobots).

1) Import the robotpkg signing key (store it in the APT keyrings directory):

```bash
sudo mkdir -p /etc/apt/keyrings
curl -fsSL http://robotpkg.openrobots.org/packages/debian/robotpkg.asc |
	sudo tee /etc/apt/keyrings/robotpkg.asc
```

2) Register the robotpkg apt repository. Replace `$(lsb_release -cs)` with your distribution codename if needed (for example `jammy`, `focal`, `bookworm`):

```bash
CODENAME=$(lsb_release -cs)
sudo tee /etc/apt/sources.list.d/robotpkg.list <<EOF
deb [arch=amd64 signed-by=/etc/apt/keyrings/robotpkg.asc] http://robotpkg.openrobots.org/packages/debian/pub $CODENAME robotpkg
EOF

sudo apt update
```

3) Search for available robotpkg packages and install the ones you need. All robotpkg packages are prefixed with `robotpkg-`:

```bash
apt search robotpkg-
sudo apt install robotpkg-pinocchio
```

Notes:

- robotpkg installs everything under the /opt/openrobots prefix and does not place files outside this prefix. After installing robotpkg packages you will likely need to update environment variables so your build and runtime tools can find them. Common variables to update include `PATH`, `PKG_CONFIG_PATH`, `LD_LIBRARY_PATH` and `PYTHONPATH` (if Python packages are installed).
- Example environment adjustments (adjust paths to your installed robotpkg version):

```bash
export PATH=/opt/openrobots/bin:$PATH
export PKG_CONFIG_PATH=/opt/openrobots/lib/pkgconfig:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=/opt/openrobots/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/opt/openrobots/lib/python3/dist-packages:$PYTHONPATH
```


## Build Instructions

Make sure you are in the repository root (where `CMakeLists.txt` is located).

Run `build.sh` - using CMake with Ninja (recommended):

```bash
./build.sh
```

After building, the compiled binary (if present) will be in the `build` directory (for example `build/main`).