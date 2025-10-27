#include <pinocchio/fwd.hpp>
#include <pinocchio/spatial/se3.hpp>
#include <iostream>

int main() {
  pinocchio::SE3 T = pinocchio::SE3::Identity();
  std::cout << T << std::endl;
  return 0;
}
