#include "Hardware_and_software_protection.h"

#include <iostream>
#include <string>

HSP::HSP() { 
  name = "undefined";
  protection_class_number = 0;
  // std::cout << "Hello\n";
}
HSP::HSP(const std::string& name, int protection_class_number) {
  this->name = name;
  this->protection_class_number = protection_class_number;
}
HSP::HSP(const HSP& other) {
  name = other.name;
  protection_class_number = other.protection_class_number;
}
HSP::HSP(HSP&& other) {
  name = other.name;
  protection_class_number = other.protection_class_number;
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
void HSP::print_info(std::ostream &out) const {
  out << "\tName: " << name << std::endl;
  out << "\tProtection class number: " << protection_class_number << std::endl;
}

std::ostream& operator << (std::ostream& out, const HSP& hsp) {
  hsp.print_info(out);
  return out;
}
