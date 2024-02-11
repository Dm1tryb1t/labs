#include "Geometric_figures.h"

#include <iomanip>
#include <iostream>

Rectangle::Rectangle(double length, double width) : length(length), width(width) {}

double Rectangle::calculate_area() {
  return width * length;
}
void Rectangle::print_sidesValue() {
  std::cout << std::fixed << std::setprecision(5)
            << "\tlength = " << length << std::endl
            << "\twidth = " << width << std::endl;
}
void Rectangle::print_areaValue() {
  std::cout << std::fixed << std::setprecision(7)
            << "\tarea value: " << calculate_area() << std::endl;
}

Cuboid::Cuboid(double length, double width, double height) : Rectangle(length, width), height(height) {}

double Cuboid::calculate_area() {
  return height * Rectangle::calculate_area();
}
void Cuboid::print_sidesValue() {
  Rectangle::print_sidesValue();
  std::cout << "\theight = " << height << std::endl;
}
void Cuboid::print_areaValue() {
  std::cout << std::fixed << std::setprecision(7)
            << "\tarea value: " << Cuboid::calculate_area() << std::endl;
}
