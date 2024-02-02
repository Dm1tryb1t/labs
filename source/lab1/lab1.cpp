#include "Hardware_and_software_protection.h"

// g++ ./source/lab1/Hardware_and_software_protection.cpp ./source/lab1/lab1.cpp -o ./build/lab1

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

void solve_with_indicator() {
  std::string tmp;
  int number_of_Hardware_and_software_protection;
  while (true) {
    std::cout << "Number of Hardware and Software Protection classes: ";
    std::cin.sync();
    getline(std::cin, tmp);
    try {
      number_of_Hardware_and_software_protection = stoi(tmp);
    } catch (std::exception &e) {
      std::cout << "Error: " << tmp << ' ' << e.what() << std::endl;
      continue;
    }
    break;
  }
  Hardware_and_software_protection** protection_class = 
                new Hardware_and_software_protection*[number_of_Hardware_and_software_protection];
  std::string protection_class_name;
  int protection_class_number;
  for (int i = 0; i < number_of_Hardware_and_software_protection; ) {
    std::cout << "\t\t" << i + 1 << " Hardware and software protection class:\n";
    std::cout << "Name: ";
    std::cin.sync();
    getline(std::cin, protection_class_name);
    std::cout << "Protection class number: ";
    std::cin.sync();
    getline(std::cin, tmp);
    try {
      protection_class_number = stoi(tmp);
      if (protection_class_number > 7 || protection_class_number < 1) {
        std::cout << "Error: protection_class_number should be between 1 and 7\n";
        continue;
      }
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      continue;
    }
    protection_class[i++] = 
              new Hardware_and_software_protection(protection_class_name, protection_class_number);
  }

  while (true) {
    std::cout << "\n\nProtection class number: ";
    std::cin.sync();
    getline(std::cin, tmp);
    try {
      protection_class_number = stoi(tmp);
      if (protection_class_number > 7 || protection_class_number < 1) {
        std::cout << "Error: protection_class_number should be between 1 and 7\n";
        continue;
      }
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      continue;
    }
    break;
  }

  std::ofstream fout;
  fout.open("./output/out_lab1.txt");
  std::cout << "\t\tProtection classes that can be used for:\n";
  fout << "\t\tProtection classes that can be used for:\n";
  for (int i = 0; i < number_of_Hardware_and_software_protection; ++i) {
    if (protection_class[i]->can_be_used(protection_class_number)) {
      protection_class[i]->print_info(std::cout);
      protection_class[i]->print_info(fout);
    }
    delete protection_class[i];
  }
  fout.close();
  delete[] protection_class;
}

void solve_with_vector() {
  std::string tmp;
  int number_of_Hardware_and_software_protection;
  while (true) {
    std::cout << "Number of Hardware and Software Protection classes: ";
    std::cin.sync();
    getline(std::cin, tmp);
    try {
      number_of_Hardware_and_software_protection = stoi(tmp);
    } catch (std::exception &e) {
      std::cout << "Error: " << tmp << ' ' << e.what() << std::endl;
      continue;
    }
    break;
  }
  std::vector<Hardware_and_software_protection*> protection_classes(number_of_Hardware_and_software_protection);
  std::string protection_class_name;
  int protection_class_number;
  for (int i = 0; i < number_of_Hardware_and_software_protection; ) {
    std::cout << "\t\t" << i + 1 << " Hardware and software protection class:\n";
    std::cout << "Name: ";
    std::cin.sync();
    getline(std::cin, protection_class_name);
    std::cout << "Protection class number: ";
    std::cin.sync();
    getline(std::cin, tmp);
    try {
      protection_class_number = stoi(tmp);
      if (protection_class_number > 7 || protection_class_number < 1) {
        std::cout << "Error: protection_class_number should be between 1 and 7\n";
        continue;
      }
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      continue;
    }
    protection_classes[i++] = 
              new Hardware_and_software_protection(protection_class_name, protection_class_number);
  }

  while (true) {
    std::cout << "\n\nProtection class number: ";
    std::cin.sync();
    getline(std::cin, tmp);
    try {
      protection_class_number = stoi(tmp);
      if (protection_class_number > 7 || protection_class_number < 1) {
        std::cout << "Error: protection_class_number should be between 1 and 7\n";
        continue;
      }
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      continue;
    }
    break;
  }

  std::ofstream fout;
  fout.open("./output/out_lab1.txt");
  std::cout << "\t\tProtection classes that can be used for:\n";
  fout << "\t\tProtection classes that can be used for:\n";
  for (auto& protection_class : protection_classes) {
    if (protection_class->can_be_used(protection_class_number)) {
      protection_class->print_info(std::cout);
      protection_class->print_info(fout);
    }
    delete protection_class;
  }
  fout.close();
}

int main() {
  // solve_with_indicator();
  solve_with_vector();
  
  return 0;
}
