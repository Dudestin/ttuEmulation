#pragma once
#include <Eigen/Dense>
#include <iostream>

#include "Polar3d.hpp"

using namespace Eigen;

class Camera{
  Vector3f loc;
  Vector3f dir;
public:
  void setDir(Polar3d<float> loc);
  void setDir(Vector3f direction);
  void setLoc(Polar3d<float> loc);
  void setLoc(Vector3f loc);  

  Polar3d<float> getDir() const;
  Vector3f getLoc() const;
  
  Vector3f getRay(float u, float v);
  
};
