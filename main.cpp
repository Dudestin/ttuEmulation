#include <iostream>
#include <string>
#include "./lib/happly.h"

#include "Ray.hpp"
#include "Triangle.hpp"

void writeColor(std::ostream &out,const Ray& ray,const std::vector<Triangle>& triVector) {
  // Write the translated [0,255] value of each color component.
  for (const auto& e:triVector){
    if (e.isIntersect(ray)){
      out << 0 << ' '
	  << 0 << ' '
	  << 0 << '\n';
      return;
    }
  }
  out << 255 << ' '
      << 255 << ' '
      << 255 << '\n';
}

int main(void){
  auto triVector = Triangle::loadPLYAsTriangle("../dragon_recon/dragon_vrip_res3.ply");

  constexpr auto aspect_ratio = 16.f/9.f;
  constexpr unsigned short image_width = 384;
  constexpr unsigned short image_height = static_cast<unsigned short>(image_width / aspect_ratio);
  constexpr auto viewport_height = 2.f;
  constexpr auto viewport_width = aspect_ratio * viewport_height;
  constexpr auto focal_length = -2.f;

  Vector3d origin {-0.07,0.1,-0.3};
  Vector3d horizontal = {viewport_width,0,0};
  Vector3d vertical = {0,viewport_height,0};  
  Vector3d lower_left_corner = origin - horizontal/2 - vertical/2 - Vector3d(0,0,focal_length);

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
  for (int j = image_height-1; j>= 0;--j){
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i){
      auto u = double(i) / (image_width-1);
      auto v = double(j) / (image_height-1);
      Ray ray {origin, lower_left_corner + u*horizontal + v*vertical - origin};
      writeColor(std::cout, ray, triVector);
    }
  }

  return 0;
}
