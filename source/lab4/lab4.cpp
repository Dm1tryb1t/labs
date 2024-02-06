#include "Employee.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  std::list<Employee> employees_list;
  std::vector<Employee> employees_vec;
  std::cout << "Set the count of employees: ";
  int employees_count;
  std::cin >> employees_count;
  std::string fio, hireDate, position; int salary;
  std::ifstream fin("./input/input_lab4.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Couldn't open input file" << std::endl;
    return 1;
  }
  for (int i = 0; i < employees_count; ++i) {
    /*std::cout << "\t\t==========Employee " << i + 1 << " ==========\n";
    std::cout << "hire date: ";
    std::cin.sync();*/
    getline(fin, fio);
    getline(fin, hireDate);
    /*std::cout << "position: ";
    std::cin.sync();*/
    getline(fin, position);
    // std::cout << "salary: ";
    fin >> salary;
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
