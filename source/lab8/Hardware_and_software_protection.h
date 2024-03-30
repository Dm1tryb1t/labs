#include <iostream>
#include <string>

#ifndef HARDWARE_AND_SOFTWARE_PROTECTION_H
#define HARDWARE_AND_SOFTWARE_PROTECTION_H

class HSP {
private:  
  std::string name;
  int protection_class_number;

public:
  HSP();
  HSP(const std::string&, int);
  HSP(const HSP&);
  HSP(HSP&&);
  int get_protection_class_number();
  bool can_be_used(int);
  void print_info(std::ostream&) const;
};

std::ostream& operator << (std::ostream& out, const HSP& hsp);

#endif
