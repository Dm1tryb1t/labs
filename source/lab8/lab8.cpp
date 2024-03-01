#include "Hardware_and_software_protection.h"
#include "smartPtr.h"

#include <iostream>

// g++ source/lab8/lab8.cpp source/lab8/Hardware_and_software_protection.cpp -o build/lab8

int main() {
  MyUnique_ptr<HSP> my_ptr1(new HSP("aaa", 1));
  // std::cout << my_ptr1->get_protection_class_number() << std::endl;
  my_ptr1->print_info(std::cout);
  // MyUnique_ptr<int> my_ptr2(new int(4));
  // std::cout << *my_ptr2 << std::endl;
  // Make_MyUnique(HSP("sss", 2), Point(1, 2), HSP("ddd", 3));
  return 0;
}
