#pragma once
#include <list>
#include <vector>
#include <utility>
#include <Eigen/Dense>

#include "Triangle.hpp"

using namespace Eigen;

using Object = std::vector<Triangle>;
using Coordinate = std::pair<Object, Vector3f>;

class World{
  Vector3f origin;
  std::list<std::unique_ptr<Coordinate>> objList;
public:

};
