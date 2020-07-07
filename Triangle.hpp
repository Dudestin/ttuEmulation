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
    const float EPSILON = 0.0000001;
    using Vector3D = Vector3d;
    Vector3D vertex0 = this->v0;
    Vector3D vertex1 = this->v1;  
    Vector3D vertex2 = this->v2;
    Vector3D edge1, edge2, h, s, q;
    float a,f,u,v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = ray.direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -EPSILON && a < EPSILON)
        return false;    // This ray is parallel to this triangle.
    f = 1.0/a;
    s = ray.origin - vertex0;
    u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = s.cross(edge1);
    v = f * ray.direction.dot(q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dot(q);
    if (t > EPSILON) // ray intersection
    {
        // outIntersectionPoint = rayOrigin + rayVector * t;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;



    // Matrix3d A;
    // A << -ray.direction, v1-v0, v2-v0;
    // Vector3d x = A.householderQr().solve(ray.origin-v0);
    // if (x(0) >= 0 && x(1) >= 0 && x(2) >= 0 && x(1)+x(2) <= 1){
    //   return true;
    // }
    // return false;
  }
  
  template <typename T>
  Triangle(const std::array<T, 3>& arr0,const std::array<T, 3>& arr1,const std::array<T, 3>& arr2) :
    v0 {arr0[0],arr0[1],arr0[2]},
    v1 {arr1[0],arr1[1],arr1[2]},
    v2 {arr2[0],arr2[1],arr2[2]} {}

  static std::vector<Triangle> loadPLYAsTriangle(const std::string& filename){
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
