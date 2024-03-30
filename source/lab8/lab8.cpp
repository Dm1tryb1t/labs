#include "Hardware_and_software_protection.h"
#include "smartPtr.h"

#include <iostream>
#include <list>
#include <memory>
// g++ source/lab8/lab8.cpp source/lab8/Hardware_and_software_protection.cpp -o build/lab8

// template<class T> std::list<MyUnique_ptr<T>> lst;
int main() {
  
  // MyShared_ptr<HSP> my_ptr1(new HSP("aaa", 1));
  // // // std::cout << my_ptr1->get_protection_class_number() << std::endl;
  // std::cout << my_ptr1;
  auto ptr_container1 = create_unique<HSP>(HSP(), HSP("aaa", 1),
                              HSP("bbb", 2), HSP("ccc", 3), HSP("ccc", 4));
  auto ptr_container2 = create_shared<HSP>(HSP(), HSP("aaa", 1),
                              HSP("bbb", 2), HSP("ccc", 3), HSP("ccc", 4));
  for (const auto& el : ptr_container1) {
    std::cout << el;
  }
  std::cout << std::endl;
  for (const auto& el : ptr_container2) {
    std::cout << el;
  }
  // MyUnique_ptr<int> my_ptr2(new int(4));
  // std::cout << *my_ptr2 << std::endl;
  // Make_MyUnique(HSP("sss", 2), Point(1, 2), HSP("ddd", 3));
  return 0;
}
