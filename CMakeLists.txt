cmake_minimum_required(VERSION 3.10)
project(RobotControl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Eigen3 REQUIRED)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Eigen3::Eigen)