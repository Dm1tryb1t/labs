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

  std::cout << "\t\tRectangle parameters:\n";
  rectangle->print_sidesValue();
  rectangle->print_areaValue();
  
  std::cout << "\t\tCuboid parameters:\n";
  cuboid->print_sidesValue();
  try {
    cuboid->print_areaValue();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  
  delete rectangle;
  delete cuboid;
  return 0;
}
