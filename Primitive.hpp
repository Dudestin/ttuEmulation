#pragma once

#include "Ray.hpp"

struct Primitive{
  virtual bool isIntersect(const Ray& ray) const = 0;
  virtual ~Primitive() {};
};
