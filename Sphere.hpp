#pragma once
#include <Eigen/Dense>

#include "Ray.hpp"

using namespace Eigen;

struct Sphere{
  Vector3f v0;
  float r;
public:
  bool isIntersect(const Ray& ray) const;
};
