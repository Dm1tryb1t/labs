#include "Vector.h"

#include <iostream>

Vector::Vector() {
  elems = nullptr;
  sz = 0;
  // std::cout << "Empty vector" << std::endl;
}
Vector::Vector(double* arr, int size) {
  sz = size;
  elems = new double[sz];
  for (int i = 0; i < sz; ++i) elems[i] = arr[i];
  // std::cout << "vector whith array" << std::endl;
}
Vector::Vector(const Vector& other_vec) {
  sz = other_vec.sz;
  elems = new double[sz];
  for (int i = 0; i < sz; ++i) elems[i] = other_vec.elems[i];
  // std::cout << "vector whith another one copy " << std::endl;
}
Vector::Vector(Vector&& other_vec) {
  //if (elems) delete[] elems;
  elems = nullptr;
  sz = 0;
  std::swap(sz, other_vec.sz);
  std::swap(elems, other_vec.elems);
  // std::cout << "vector whith another one replace" << std::endl;
}
Vector::~Vector() {
  if (elems) {
    delete[] elems;
    sz = 0;
    // std::cout << "Vector is cleared." << std::endl;
  }
  elems = nullptr;
}

int Vector::size() {
  return sz;
}
bool Vector::empty() {
  return sz == 0;
}
void Vector::clear() {
  if (sz == 0) return;
  delete[] elems;
  elems = nullptr;
  sz = 0;
  // std::cout << "Vector is cleared" << std::endl;
}

double Vector::operator [] (int idx) {
  if (idx >= sz || idx < 0) {
    std::cerr << "Index out of range" << std::endl;
    return 1e9 + 1;
  }
  return elems[idx];
}
Vector& Vector::operator = (const Vector& other_vec) {
  if (elems == other_vec.elems) return *this;
  if (elems) delete[] elems;
  sz = other_vec.sz;
  elems = new double[sz];
  for (int i = 0; i < sz; ++i) elems[i] = other_vec.elems[i];
  std::cout << "copy value" << std::endl;
  return *this;
}
Vector& Vector::operator = (Vector&& other_vec) {
  if (elems) delete[] elems;
  sz = 0;
  elems = nullptr;
  std::swap(sz, other_vec.sz);
  std::swap(elems, other_vec.elems);
  std::cout << "replace object" << std::endl;
  return *this;
}

std::istream& operator >> (std::istream& in, Vector& vec) {
  int sz;
  in >> sz;
  double* arr = new double[sz];
  for (int i = 0; i < sz; ++i) {
    in >> arr[i];
  }
  vec = Vector(arr,sz);
  if (arr) delete[] arr;
  return in;
}
std::ostream& operator << (std::ostream& out, Vector& vec) {
  out << vec.size() << '\n';
  for (int i = 0; i < vec.size(); ++i) {
    out << vec[i] << ' ';
  }
  out << std::endl;
  return out;
}

Vector operator + (Vector& vec1, Vector& vec2) {
  int sz = vec1.size() + vec2.size();
  double* arr = new double[sz];
  for (int i = 0; i < vec1.size(); ++i) arr[i] = vec1[i];
  for (int i = 0; i < vec1.size(); ++i) arr[vec1.size() + i] = vec2[i];
  Vector res_vec(arr, sz);
  if (arr) delete[] arr;
  return res_vec;
}

Vector& Vector::operator ++ () {
  for (int i = 0; i < sz; ++i) ++elems[i];
  return *this;
}
Vector Vector::operator ++ (int) {
  Vector vec = *this;
  for (int i = 0; i < sz; ++i) elems[i]++;
  return vec;
}
