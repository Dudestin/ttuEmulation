#pragma once
#include <Eigen/Dense>
#include <limits>

#include "Ray.hpp"
#include "Primitive.hpp"

struct PlanePrimitive : Primitive{
  static constexpr float EPSILON {std::numeric_limits<float>::epsilon()};
public:
  Eigen::Vector3f N;
  Eigen::Vector3f P0;  
  float r;

  PlanePrimitive(const Eigen::Vector3f& n, const Eigen::Vector3f& p0):N{n},P0{p0} {}

  bool isIntersect(const Ray& ray) const override{
    float denom = N.dot(ray.origin);
    if (denom > EPSILON) {
      Eigen::Vector3f p010 = P0 - ray.origin;
      float t = p010.dot(N) / denom;
      return (t >=0);
    }
    return false;
  }
};
