#pragma once
#include <Eigen/Core>
#include <list>
#include <memory>

#include "Object.hpp"
#include "Color.hpp"

class Scene{
  Eigen::Vector3f origin;
  using objPtrWithCoordinate = std::pair<std::shared_ptr<Object>,Eigen::Vector3f>;
  std::vector<objPtrWithCoordinate> objVector;
public:
  Scene(): Scene{{0,0,0}} {}
  Scene(Eigen::Vector3f o0): origin{o0} {}

  void insertPrimitive(std::shared_ptr<Object>&& ptr,const Eigen::Vector3f& loc){
    objVector.emplace_back(std::move(ptr), loc+origin);
  }
  void insertPrimitive(const std::shared_ptr<Object>& ptr,const Eigen::Vector3f& loc){
    objVector.emplace_back(std::move(ptr), loc+origin);
  }
};

