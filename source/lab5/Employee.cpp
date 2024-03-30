#include "Employee.h"

#include <iostream>
#include <string>

Employee::Employee() {
  hireDate = position = "undefined";
  salary = 0;
}
Employee::Employee(std::string fio, std::string hireDate, std::string position, int salary) {
  this->fio = fio;
  this->hireDate = hireDate;
  this->position = position;
  this->salary = salary;
}
Employee::Employee(const Employee& employee) {
  fio = employee.fio;
  hireDate = employee.hireDate;
  position = employee.position;
  salary = employee.salary;
  /*this->fio = employee.getFio();
  this->hireDate = employee.getHireDate();
  this->position = employee.getPosition();
  this->salary = employee.getSalary();*/
}

std::string Employee::getFio() const {
  return fio;
}
std::string Employee::getHireDate() const {
  return hireDate;
}
std::string Employee::getPosition() const {
  return position;
}
int Employee::getSalary() const {
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

/*size_t Employee::HashFunction::operator()(Employee employee) const {
  return std::hash<int>()(employee.getSalary());
}*/

size_t MyHashFunction::operator()(const Employee& employee) const {
  size_t hash = employee.getSalary();
  for (char sym : employee.getFio()) {
    hash += (int)sym;
  }
  return hash;
}

bool operator < (const Employee& first, const Employee& second) {
  if (first.getSalary() == second.getSalary()) return first.getFio() < second.getFio();
  return first.getSalary() < second.getSalary();
}
// bool operator > (const Employee& first, const Employee& second) {
//   if (first.getSalary() == second.getSalary()) return first.getFio() > second.getFio();
//   return first.getSalary() > second.getSalary();
// }
bool operator == (const Employee& first, const Employee& second) {
  return first.getFio() == second.getFio();
}



std::ostream& operator << (std::ostream& out, const Employee& employee) {
  return out << "\tFIO: " << employee.getFio() << std::endl
      << "\thire date: " << employee.getHireDate() << std::endl
      << "\tposition: " << employee.getPosition() << std::endl
      << "\tsalary: " << employee.getSalary() << std::endl;
}
