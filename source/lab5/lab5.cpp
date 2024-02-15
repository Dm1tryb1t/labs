#include "Employee.h"

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
// #include <functional>

// g++ source/lab5/lab5.cpp source/lab5/Employee.cpp -o build/lab5

// using Comp = std::function<bool(const Employee& first, const Employee& second)>;



std::string tmp; 
int main() {
  // std::set<Employee, Comp> employees_set(
  //   [](const Employee& first, const Employee& second) {
  //     return first.getSalary() < second.getSalary();
  //   });
  // std::unordered_set<Employee, Employee::HashFunction> employees_uset;
  std::set<Employee> employees_set;
  std::unordered_set<Employee, MyHashFunction> employees_uset;
  int employees_count;
  std::ifstream fin;
  fin.open("./input/input_lab5.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Could not open input file" << std::endl;
    return 1;
  }
  getline(fin, tmp);
  try {
    employees_count = std::stoi(tmp);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: Invalid employees' count" << std::endl;
    std::cerr << e.what() << std::endl;
    fin.close();
    return 1;
  }
  std::string fio;
  std::string hireDate;
  std::string position;
  int salary;
  for (int i = 0; i < employees_count; ++i) {
    getline(fin, fio);
    getline(fin, hireDate);
    getline(fin, position);
    getline(fin, tmp);
    try {
      salary = std::stoi(tmp);
    } catch (const std::invalid_argument &e) {
      std::cerr << "Error: Invalid salary" << std::endl;
      std::cerr << e.what() << std::endl;
      fin.close();
      return 1;
    }
    employees_set.insert(Employee(fio, hireDate, position, salary));
    employees_uset.insert(Employee(fio, hireDate, position, salary));
  }
  fin.close();
  std::ofstream fout_set;
  fout_set.open("./output/out_set_lab5.txt");
  if (!fout_set.is_open()) {
    std::cerr << "Error: Could not open output file" << std::endl;
    return 1;
  }
  for (const auto& employee : employees_set) {
    fout_set << employee;
    std::cout << employee;
  }
  fout_set.close();
  std::ofstream fout_uset;
  fout_uset.open("./output/out_uset_lab5.txt");
  if (!fout_uset.is_open()) {
    std::cerr << "Error: Could not open output file" << std::endl;
    return 1;
  }
  for (const auto& employee : employees_uset) {
    fout_uset << employee;
  }
  fout_uset.close();
  return 0;
}
