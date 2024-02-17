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
  Employee(const Employee&);
  std::string getFio() const;
  std::string getHireDate() const;
  std::string getPosition() const ;
  int getSalary() const;
  // .Employee(Employee&);
  void updateSalary(int);
  Employee& operator = (Employee&);
};

class MyHashFunction {
public:
  
  size_t operator()(const Employee& employee) const;
};

bool operator < (const Employee& first, const Employee& second);
// bool operator <= (const Employee& first, const Employee& second);
bool operator > (const Employee& first, const Employee& second);
// bool operator >= (const Employee& first, const Employee& second);
bool operator == (const Employee& first, const Employee& second);
// bool operator != (const Employee& first, const Employee& second);

std::ostream& operator << (std::ostream&, const Employee&);

#endif
