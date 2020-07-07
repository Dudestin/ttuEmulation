#pragma once
#include <Eigen/Dense>
#include <tuple>
#include <vector>

#include "./lib/happly.h"
#include "Ray.hpp"

using namespace Eigen;

struct Triangle{
  Vector3d v0,v1,v2;
public:
  bool isIntersect(const Ray& ray) const{
    Matrix3d A;
    A << -ray.direction, v1-v0, v2-v0;
    Vector3d x = A.householderQr().solve(ray.origin-v0);
    if (x(0) >= 0 && x(1) >= 0 && x(2) >= 0 && x(1)+x(2) <= 1){
      return true;
    }
    return false;
  }
  
  template <typename T>
  Triangle(std::array<T, 3> arr0,std::array<T, 3> arr1,std::array<T, 3> arr2){
    v0 = {arr0[0],arr0[1],arr0[2]};
    v1 = {arr1[0],arr1[1],arr1[2]};
    v2 = {arr2[0],arr2[1],arr2[2]};    
  }

  static std::vector<Triangle> loadPLYAsTriangle(std::string filename){
    happly::PLYData plyIn(filename);
    auto vertices = plyIn.getVertexPositions();
    auto facies = plyIn.getFaceIndices<size_t>();
    std::vector<Triangle> triangleVec;
    for (const auto& x:facies){
      triangleVec.emplace_back(vertices[x[0]],vertices[x[1]],vertices[x[2]]);
    }
    return triangleVec;
  }
};

std::ostream& operator<<(std::ostream& os, const Triangle& value){
  os << "Triangle Vertices" << std::endl;
  os << "Vertex0: " << value.v0 << std::endl;
  os << "Vertex1: " << value.v1 << std::endl;
  os << "Vertex2: " << value.v2 << std::endl;
  return os;
}
