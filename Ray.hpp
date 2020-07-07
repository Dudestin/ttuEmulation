#pragma once
#include <Eigen/Dense>

using namespace Eigen;

struct Ray{
public:
  Vector3f origin,direction;
  Ray(const Vector3f& orig,const Vector3f& dir) : origin(orig), direction(dir.normalized()) {}
};
