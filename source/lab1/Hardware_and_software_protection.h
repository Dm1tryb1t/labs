#include <iostream>
#include <string>

#ifndef HARDWARE_AND_SOFTWARE_PROTECTION_H
#define HSPHARDWARE_AND_SOFTWARE_PROTECTION_H

class HSP {
private:  
  std::string name;
  int protection_class_number;

public:
  HSP();
  HSP(const std::string& name, int protection_class_number);
  int get_protection_class_number();
  bool can_be_used(int protection_class_number);
  void print_info(std::ostream&);
};


#endif
