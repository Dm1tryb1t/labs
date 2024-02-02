#include "Employee.h"

#include <fstream>
#include <iostream>
#include <set>
#include <unordered_set>

int main() {
  std::set<Employee> employees_set;
  // std::unordered_set<Employee> employees_uset;
  std::ifstream fin;
  fin.open("input_lab5.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Could not open input file" << std::endl;
  }
  // ...
  fin.close();
  return 0;
}
