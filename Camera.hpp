#pragma once
#include <Eigen/Dense>
#include <iostream>

#include "Polar3d.hpp"

using namespace Eigen;

class Camera{
  Vector3d loc;
  Vector3d dir;
public:
  void setDir(Polar3d<float> loc);
  void setDir(Vector3d direction);
  void setLoc(Polar3d<float> loc);
  void setLoc(Vector3d loc);  

  Polar3d<float> getDir() const;
  Vector3d getLoc() const;
  
  Vector3d getRay(float u, float v);
  
};
