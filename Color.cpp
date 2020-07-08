#include "Color.hpp"

unsigned short Color::getR() const noexcept{
  return static_cast<unsigned short>(this->r);
}

unsigned short Color::getG() const noexcept{
  return static_cast<unsigned short>(this->g);
}

unsigned short Color::getB() const noexcept{
  return static_cast<unsigned short>(this->b);
}

unsigned short Color::getAlpha() const noexcept{
  return static_cast<unsigned short>(this->alpha);
}

Eigen::Vector3f Color::getColorAsVector() const{
  return Eigen::Vector3f(this->r,this->g,this->b,this->alpha);
}

void Color::setR(const float R){
  this->r = R;
}

void Color::setG(const float G){
  this->g = G;
}

void Color::setB(const float B){
  this->b = B;
}

void Color::setAlpha(const float Alpha){
  this->alpha = Alpha;
}
