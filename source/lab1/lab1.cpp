#include "Hardware_and_software_protection.h"

// g++ ./source/lab1/Hardware_and_software_protection.cpp ./source/lab1/lab1.cpp -o ./build/lab1

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

int solve_with_indicator() {
  std::ifstream fin;
  fin.open("./input/input_lab1.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Cannot open input file" << std::endl;
    return 1;
  }
  int number_of_Hardware_and_software_protection;
  fin >> number_of_Hardware_and_software_protection;
  Hardware_and_software_protection** protection_class = 
                new Hardware_and_software_protection*[number_of_Hardware_and_software_protection];
  std::string protection_class_name;
  int protection_class_number;
  for (int i = 0; i < number_of_Hardware_and_software_protection; ++i) {
    getline(fin, protection_class_name);
    fin >> protection_class_number;
    protection_class[i] = 
              new Hardware_and_software_protection(protection_class_name, protection_class_number);
  }
  fin >> protection_class_number;
  fin.close();

  std::ofstream fout;
  fout.open("./output/out_lab1.txt");
  if (!fout.is_open()) {
    std::cerr << "Error: Cannot open output file" << std::endl;
    return 1;
  }
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
  return 0;
}

int solve_with_vector() {
  std::ifstream fin;
  fin.open("./input/input_lab1.txt");
  if (!fin.is_open()) {
    std::cerr << "Error: Cannot open input file" << std::endl;
    return 1;
  }
  int number_of_Hardware_and_software_protection;
  fin >> number_of_Hardware_and_software_protection;
  std::vector<Hardware_and_software_protection*> protection_class(number_of_Hardware_and_software_protection); 
  std::string protection_class_name;
  int protection_class_number;
  for (int i = 0; i < number_of_Hardware_and_software_protection; ++i) {
    getline(fin, protection_class_name);
    fin >> protection_class_number;
    protection_class[i] = 
              new Hardware_and_software_protection(protection_class_name, protection_class_number);
  }
  fin >> protection_class_number;
  fin.close();
  
  std::ofstream fout;
  fout.open("./output/out_lab1.txt");
  if (!fout.is_open()) {
    std::cerr << "Error: Cannot open output file" << std::endl;
    return 1;
  }
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
  return 0;
}

int main() {
  return solve_with_indicator();
  return solve_with_vector();
}
