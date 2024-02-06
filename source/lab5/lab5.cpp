#include "Employee.h"

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

// g++ source/lab5/lab5.cpp source/lab5/Employee.cpp -o build/lab5

int main() {
  std::set<Employee> employees_set;
  // std::unordered_set<Employee, Employee::HashFunction> employees_uset;
  int employees_count;
  std::ifstream fin;
  fin.open("input_lab5.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Could not open input file" << std::endl;
    return 1;
  }
  fin >> employees_count;
  std::string fio;
  std::string hireDate;
  std::string position;
  int salary;
  for (int i = 0; i < employees_count; ++i) {
    getline(fin, fio);
    getline(fin, hireDate);
    getline(fin, position);
    fin >> salary;
    employees_set.insert(Employee(fio, hireDate, position, salary));
    //  employees_uset.insert(Employee(fio, hireDate, position, salary));
  }
  fin.close();
  std::ofstream fout_set;
  fout_set.open("out_set_lab5.txt");
  if (!fout_set.is_open()) {
    std::cerr << "Error: Could not open output file" << std::endl;
    return 1;
  }
  for (auto employee : employees_set) {
    fout_set << employee;
  }
  fout_set.close();
  std::ofstream fout_uset;
  fout_uset.open("out_uset_lab5.txt");
  if (!fout_uset.is_open()) {
    std::cerr << "Error: Could not open output file" << std::endl;
    return 1;
  }
  /*for (auto employee : employees_uset) {
    fout_uset << employee;
  }*/ fout_uset.close();
  return 0;
}
