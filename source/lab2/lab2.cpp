#include "Vector.h"

// g++ source/lab2/lab2.cpp source/lab2/Vector.cpp -o build/lab2

#include <fstream>
#include <iostream>
#include <string>

int main() {
  double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  std::ifstream in;
  Vector vec1;
  Vector vec2;
  Vector vec3(arr, 5);
  in.open("./input/input_lab2.txt");
  if (!in.is_open()) {
    std::cerr << "Error: Could not open input file\n";
    return 1;
  }
  in >> vec2;
  in.close();
  vec1 = vec2;
  vec1 = vec1 + vec2;
  std::cout << vec1[0] << ' ' << vec1[1] << ' ' << vec1[2] << std::endl;
  vec1 = vec1;
  std::cout << vec1[0] << ' ' << vec2[0] << std::endl;
  vec2 = vec1++;
  std::cout << vec1[0] << ' ' << vec2[0] << std::endl;
  vec2 = ++vec1;
  std::cout << vec1[0] << ' ' << vec2[0] << std::endl;
  std::cout << vec1[0] << ' ' << vec1[1] << ' ' << vec1[2] << std::endl;
  std::ofstream out;
  out.open("./output/output_lab2.txt");
  if (!out.is_open()) {
    std::cerr << "Error: Could not open output file\n";
    return 1;
  }
  out << vec1 << vec2 << vec3;
  out.close();
  return 0;
}
