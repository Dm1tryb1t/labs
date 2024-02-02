#include "Employee.h"

#include <iostream>
#include <string>

Employee::Employee() {
  hireDate = position = "undefined";
  salary = 0;
}
Employee::Employee(std::string hireDate, std::string position, int salary) {
  this->hireDate = hireDate;
  this->position = position;
  this->salary = salary;
}
/*Employee::Employee(Employee& employee) {
  this->hireDate = employee.getHireDate();
  this->position = employee.getPosition();
  this->salary = employee.getSalary();
}*/

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
  this->hireDate = employee.getHireDate();
  this->position = employee.getPosition();
  this->salary = employee.getSalary();
  return *this;
}

std::ostream& operator << (std::ostream& out, Employee& employee) {
  return out << "\thire date: " << employee.getHireDate() << std::endl
      << "\tposition: " << employee.getPosition() << std::endl
      << "\tsalary: " << employee.getSalary() << std::endl;
}
