#include "Employee.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// g++ source/lab4/lab4.cpp source/lab4/Employee.cpp -o build/lab4

std::string tmp;
int main() {
  std::list<Employee> employees_list;
  std::vector<Employee> employees_vec;
  std::ifstream fin("./input/input_lab4.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Couldn't open input file" << std::endl;
    return 1;
  }
  int employees_count;
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
    employees_list.push_back(Employee(fio, hireDate, position, salary));
  }
  fin.close();
  employees_vec.resize(employees_count);
  std::copy(employees_list.begin(), employees_list.end(), employees_vec.begin());
  employees_list.sort([](Employee a, Employee b) {
    return a.getSalary() > b.getSalary();
  });
  std::ofstream out_list, out_vec;
  out_vec.open("./output/out_vec_lab4.txt");
  if (!out_vec.is_open()) {
    std::cerr << "Error: Cannot open vector output file\n";
    return 1;
  } 
  int i = 1;
  for (Employee& employee : employees_vec) {
    out_vec << "\t\t==========Employee " << i++ << " ==========\n";
    out_vec << employee;
  }
  out_vec.close();
  out_list.open("./output/out_list_lab4.txt");
  if (!out_list.is_open()) {
    std::cerr << "Error: Cannot open list output file\n";
    return 1;
  }
  i = 1;
  for (Employee& employee : employees_list) {
    out_list << "\t\t==========Employee " << i++ << " ==========\n";
    out_list << employee;
  }
  out_list.close();
  return 0;
}
