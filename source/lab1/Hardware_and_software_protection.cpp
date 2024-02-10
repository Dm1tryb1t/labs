#include "Hardware_and_software_protection.h"

#include <iostream>
#include <string>

HSP::HSP() { 
  name = "undefined";
  protection_class_number = 0;
  std::cout << "Hello\n";
}
HSP::HSP(const std::string& name, int protection_class_number) {
  this->name = name;
  this->protection_class_number = protection_class_number;
}
int HSP::get_protection_class_number() {
  return protection_class_number;
}
bool HSP::can_be_used(int protection_class_number) {
  if (this->protection_class_number == 0) {
    std::cout << "SP is undefined\n";
    return false;
  }
  return this->protection_class_number <= protection_class_number;
}
void HSP::print_info(std::ostream &out) {
  out << "\tName: " << name << std::endl;
  out << "\tProtection class number: " << protection_class_number << std::endl;
}
