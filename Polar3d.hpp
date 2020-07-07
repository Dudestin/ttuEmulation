#pragma once

template <typename FloatType>
struct Polar3d{
  FloatType r,theta,rho;

public:
  FloatType getR() const;
  FloatType getTheta() const;
  FloatType getRho() const;

  void setR(FloatType r);
  void setTheta(FloatType theta);
  void setRho(FloatType rho);
};
