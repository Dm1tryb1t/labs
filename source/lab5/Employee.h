#include <iostream>
#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
protected:
  std::string fio;
  std::string hireDate;
  std::string position;
  int salary;

public:
  Employee();
  Employee(std::string, std::string, std::string, int);
  std::string getFio();
  std::string getHireDate();
  std::string getPosition();
  int getSalary();
  // .Employee(Employee&);
  void updateSalary(int);
  Employee& operator = (Employee&);
  /*class HashFunction {
  public:
    size_t operator () (Employee) const;
  };*/
};

bool operator < (Employee& first, Employee& second);
bool operator > (Employee& first, Employee& second);
bool operator == (Employee& first, Employee& second);

std::ostream& operator << (std::ostream&, Employee&);

#endif
