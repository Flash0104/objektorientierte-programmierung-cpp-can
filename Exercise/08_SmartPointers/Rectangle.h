#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
  double width;
  double height;

public:
  Rectangle(double w, double h);
  double calculate_area() const;

  double getWidth() const;
  void setWidth(double w);
  double getHeight() const;
  void setHeight(double h);
};

#endif // RECTANGLE_H
