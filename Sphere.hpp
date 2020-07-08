#pragma once
#include <Eigen/Dense>

#include "Ray.hpp"
#include "Primitive.hpp"

struct Sphere : Primitive{
  Eigen::Vector3f center;
  float r;
public:
  bool isIntersect(const Ray& ray) const override{
    auto oc = ray.origin - center;
    float a = ray.direction.dot(ray.direction);
    float b = 2.0 * oc.dot(ray.direction);
    float c = oc.dot(oc) - pow(r,2);
    float discriminant = pow(b,2) - 4*a*c;
    return (discriminant > 0);
  }
};
