#include "Circle.h"

Circle::Circle(double r) : radius(r) {}

double Circle::calculate_area() const {
  const double PI = 3.141;
  return radius * radius * PI;
}

double Circle::getRadius() const { return radius; }
void Circle::setRadius(double r) { radius = r; }
