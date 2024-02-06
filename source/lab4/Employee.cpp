#include "Employee.h"

#include <iostream>
#include <string>

Employee::Employee() {
  fio = hireDate = position = "undefined";
  salary = 0;
}
Employee::Employee(std::string fio, std::string hireDate, std::string position, int salary) {
  this->fio = fio;
  this->hireDate = hireDate;
  this->position = position;
  this->salary = salary;
}
Employee::Employee(Employee& employee) {
  fio = employee.fio;
  hireDate = employee.hireDate;
  position = employee.position;
  salary = employee.salary;
  /*this->hireDate = employee.getHireDate();
  this->position = employee.getPosition();
  this->salary = employee.getSalary();*/
}

std::string Employee::getFio() {
  return fio;
}
std::string Employee::getHireDate() {
  return hireDate;
}
std::string Employee::getPosition() {
  return position;
}
int Employee::getSalary() {
  return salary;
}
void Employee::updateSalary(int salary) {
  this->salary = salary;
}

Employee& Employee::operator = (Employee& employee) {
  this->fio = employee.getFio();
  this->hireDate = employee.getHireDate();
  this->position = employee.getPosition();
  this->salary = employee.getSalary();
  return *this;
}

std::ostream& operator << (std::ostream& out, Employee& employee) {
  return out << "\tFIO: " << employee.getFio() << std::endl
      << "\thire date: " << employee.getHireDate() << std::endl
      << "\tposition: " << employee.getPosition() << std::endl
      << "\tsalary: " << employee.getSalary() << std::endl;
}
