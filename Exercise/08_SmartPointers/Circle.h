#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
  double radius;

public:
  Circle(double r);
  double calculate_area() const;

  double getRadius() const;
  void setRadius(double r);
};

#endif // CIRCLE_H
