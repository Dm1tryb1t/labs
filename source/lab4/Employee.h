#include <iostream>
#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
protected:
  std::string hireDate;
  std::string position;
  int salary;

public:
  Employee();
  Employee(std::string, std::string, int);
  std::string getHireDate();
  std::string getPosition();
  int getSalary();
  // .Employee(Employee&);
  void updateSalary(int);
  Employee& operator = (Employee&);
};

std::ostream& operator << (std::ostream&, Employee&);

#endif
