#include "Hardware_and_software_protection.h"
#include "smartPtr.h"

#include <iostream>

// g++ source/lab8/lab8.cpp source/lab8/Hardware_and_software_protection.cpp source/lab8/smartPtr.cpp -o build/lab8

int main() {
  MyUnique_ptr<HSP> my_ptr1(new HSP("aaa", 1));
  std::cout << my_ptr1->get_protection_class_number() << std::endl;
  // MyUnique_ptr<int> my_ptr2(new int(4));
  // std::cout << *my_ptr2 << std::endl;
  
  return 0;
}
