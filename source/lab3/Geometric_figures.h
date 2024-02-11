
#ifndef GEOMETRIC_FIGURES_H
#define GEOMETRIC_FIGURES_H

class Rectangle {
protected:
  double length;
  double width;

public:
  Rectangle();
  Rectangle(double length, double width);

  virtual double calculate_area();
  virtual void print_sidesValue();
  virtual void print_areaValue();
};

class Cuboid : public Rectangle {
protected:
  double height;

public:
  Cuboid();
  Cuboid(double length, double width, double height);

  double calculate_area() override;
  void print_sidesValue() override;
  void print_areaValue() override;
};

#endif
