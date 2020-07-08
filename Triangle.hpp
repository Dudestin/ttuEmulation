#pragma once
#include <Eigen/Core>
#include <vector>
#include <limits>

#include "./lib/happly.h"
#include "Ray.hpp"
#include "Primitive.hpp"

using namespace Eigen;

struct Triangle : Primitive{
  Vector3f v0,v1,v2;
  static constexpr double EPSILON {std::numeric_limits<float>::epsilon()};

  bool isIntersect(const Ray& ray) const override{
    using Vector3D = Vector3f;
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
