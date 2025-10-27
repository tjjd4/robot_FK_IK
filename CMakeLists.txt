cmake_minimum_required(VERSION 3.16)
project(RobotControl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 讓 CMake 能找到 robotpkg（/opt/openrobots）
list(APPEND CMAKE_PREFIX_PATH "/opt/openrobots")

# 執行檔執行時自帶 rpath，不必設 LD_LIBRARY_PATH
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
list(APPEND CMAKE_INSTALL_RPATH "/opt/openrobots/lib")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(pinocchio REQUIRED)
find_package(coal REQUIRED)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Eigen3::Eigen pinocchio::pinocchio coal::coal)
