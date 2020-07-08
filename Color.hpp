#pragma once
#include <Eigen/Core>

struct Color{
  float r,g,b,alpha;
public:
  Color(const float R,const float G,const float B,const float Alpha) :r{R},g{G},b{B},alpha{Alpha} {} 
  Color(const Eigen::Vector3f& vec) :r{vec(0)},g{vec(1)},b{vec(2)},alpha{vec(3)} {}
  unsigned short getR() const noexcept;
  unsigned short getG() const noexcept;
  unsigned short getB() const noexcept;  
  unsigned short getAlpha() const noexcept;
  Eigen::Vector3f getColorAsVector() const;

  void setR(const float R);
  void setG(const float G);
  void setB(const float B);
  void setAlpha(const float alpha);
};
