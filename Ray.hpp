#pragma once
#include <Eigen/Dense>

using namespace Eigen;

struct Ray{
public:
  Vector3d origin,direction;
  Ray(const Vector3d& orig,const Vector3d& dir) : origin(orig), direction(dir.normalized()) {}
};
