#include "Geometric_figures.h"

// g++ ./source/lab3/Geometric_figures.cpp ./source/lab3/lab3.cpp -o ./build/lab3

#include <fstream>
#include <iostream>

int main() {
  double length, width, height;
  std::cout << "Length = "; std::cin >> length;
  std::cout << "Width = "; std::cin >> width;
  std::cout << "Height = "; std::cin >> height;
  
  Rectangle* rectangle = new Rectangle(length, width);
  Cuboid* cuboid = new Cuboid(length, width, height);

  Cuboid cub(length, width, height);
  Rectangle* rect1 = &cub;
  Rectangle rect2 = cub;

  std::cout << "\t\tRectangle parameters:\n";
  // rectangle->print_sidesValue();
  // rectangle->print_areaValue();
  rect2.print_sidesValue();
  rect2.print_areaValue();

  std::cout << "\t\tCuboid parameters:\n";
  // cuboid->print_sidesValue();
  // cuboid->print_areaValue();
  rect1->print_sidesValue();
  rect1->print_areaValue();
  delete rectangle;
  delete cuboid;
  return 0;
}
