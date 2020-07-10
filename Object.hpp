#pragma once
#include <string>
#include <vector>
#include <Eigen/Core>

#include "Triangle.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "./lib/happly.h"

struct Object{
public:
  size_t getSize() const{
    return sizeof(*this);
  }
  // virtual float getWidth(const char axis) const = 0;
  // virtual Eigen::Vector3f getOriginAsRelative() const = 0;
};

struct TriangleMeshObject : Object{
  std::vector<TrianglePrimitive> primVec;
public:
  // construct from PLY file
  TriangleMeshObject(const std::string& filename) {
    happly::PLYData plyIn(filename);
    auto vertices = plyIn.getVertexPositions();
    auto facies = plyIn.getFaceIndices<size_t>();
    for (const auto& x:facies){
      this->primVec.emplace_back(vertices[x[0]],vertices[x[1]],vertices[x[2]]);
    }
  }
  // float getWidth(const char axis) const override final{
  // return 0.f;
  // }  
};

struct SphereObject : Object{
  SpherePrimitive prim;
public:
  SphereObject(const Eigen::Vector3f& cnt,float r): prim{cnt,r} {}
  // float getWidth(const char) const override final{
  // return 2*(this->prim.radius);
  // }
};

struct PlaneObject : Object{
  PlanePrimitive prim;
public:
  PlaneObject(const Eigen::Vector3f& n, const Eigen::Vector3f& p0) :prim{n,p0} {}
  // float getWidth(char axis) const overide final;
};
