#pragma once
#include "Ray.hpp"
#include "Color.hpp"

class Material{
public:
  virtual bool scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const = 0;
};

