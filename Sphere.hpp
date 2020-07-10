#pragma once
#include <Eigen/Dense>

#include "Ray.hpp"
#include "Primitive.hpp"

struct SpherePrimitive : Primitive{
public:
  Eigen::Vector3f center;
  float radius;
  SpherePrimitive(const Eigen::Vector3f& c,float r): center{c},radius{r} {}
  bool isIntersect(const Ray& ray) const override{
    Vector3f oc = ray.origin - center;
    float a = ray.direction.dot(ray.direction);
    float b = 2.0 * oc.dot(ray.direction);
    float c = oc.dot(oc) - pow(radius,2);
    float discriminant = pow(b,2) - 4*a*c;
    return (discriminant > 0);
  }
};
