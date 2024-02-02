#include <iostream>
#include <string>

#ifndef HARDWARE_AND_SOFTWARE_PROTECTION_H
#define HARDWARE_AND_SOFTWARE_PROTECTION

class Hardware_and_software_protection {
private:  
  std::string name;
  int protection_class_number;

public:
  Hardware_and_software_protection();
  Hardware_and_software_protection(const std::string& name, int protection_class_number);
  int get_protection_class_number();
  bool can_be_used(int protection_class_number);
  void print_info(std::ostream&);
};


#endif
