#include "Vector.h"

// g++ ./source/lab2/lab2.cpp ./source/lab2/Vector.cpp -o ./build/lab2

#include <fstream>
#include <iostream>
#include <string>

// const int sz = 10;
// const char* input_filename = "input_lab2.txt";
// const char* output_filename = "output_lab2.txt";
// const char* input_path = "./input/";
// const char* output_path = "./output/";

int main() {
  std::ifstream in;
  Vector vec1;
  Vector vec2;
  in.open("./input/input_lab2.txt");
  if (!in.is_open()) {
    std::cerr << "Error: Could not open input file\n";
    return 1;
  }
  in >> vec2;
  in.close();
  vec1 = vec2;
  vec1 = vec1 + vec2;
  std::ofstream out;
  out.open("./output/output_lab2.txt");
  if (!out.is_open()) {
    std::cerr << "Error: Could not open output file\n";
    return 1;
  }
  out << vec1 << vec2;
  out.close();
  return 0;
}
