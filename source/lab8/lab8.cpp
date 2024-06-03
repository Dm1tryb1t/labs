#include "Hardware_and_software_protection.h"
#include "smartPtr.h"

#include <iostream>
#include <list>
#include <memory>
// g++ source/lab8/lab8.cpp source/lab8/Hardware_and_software_protection.cpp -o build/lab8

// template<class T> std::list<MyUnique_ptr<T>> lst;
int main() {

  {
    auto ptr_container1 = create_unique<HSP>(HSP(), HSP("aaa", 1),
                                 HSP("bbb", 2), HSP("ccc", 3), HSP("ccc", 4));
    auto ptr_container2 = create_shared<HSP>(HSP(), HSP("aaa", 1),
                                HSP("bbb", 2), HSP("ccc", 3), HSP("ccc", 4));
    // for (const auto& el : ptr_container1) {
    //   std::cout << el;
    // }
    // std::cout << std::endl;
    // for (const auto& el : ptr_container2) {
    //   std::cout << el;
    // }
    HSP* hsp1 = new HSP();
    HSP* hsp2 = new HSP();
    MyShared_ptr<HSP> shared1(hsp1);
    MyShared_ptr<HSP> shared2(shared1);
    MyShared_ptr<HSP> shared3 = MyShared_ptr<HSP>(MyShared_ptr<HSP>(hsp2));
    std::cout << "TEST " << shared1.get_ptrCount() << std::endl;
    std::cout << shared2.get_ptrCount() << std::endl;
    std::cout << shared3.get_ptrCount() << std::endl;
    {
      MyShared_ptr<HSP> shared4(shared1);
      std::cout << shared1.get_ptrCount() << std::endl;
      std::cout << shared2.get_ptrCount() << std::endl;
      std::cout << shared3.get_ptrCount() << std::endl;
      std::cout << shared4.get_ptrCount() << std::endl;
    }
    std::cout << shared1.get_ptrCount() << std::endl;
    std::cout << shared2.get_ptrCount() << std::endl;
    std::cout << shared3.get_ptrCount() << std::endl;
  }
  std::cout<<"END"<<std::endl;
  return 0;
}
