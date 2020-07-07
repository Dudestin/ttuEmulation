#pragma once
#include <list>
#include <vector>
#include <utility>
#include <Eigen/Dense>

#include "Triangle.hpp"

using namespace Eigen;

using Object = std::vector<Triangle>;
using Coordinate = std::pair<Object, Vector3d>;

class World{
  Vector3d origin;
  std::list<std::unique_ptr<Coordinate>> objList;
public:
  
};
