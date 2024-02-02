#include <iostream>

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
  double* elems;
  int sz;

public:
  Vector();
  Vector(double*, int);
  Vector(const Vector&);
  Vector(Vector&&);
  ~Vector();

  int size();
  bool empty();
  void clear();
  
  double operator [] (int);
  Vector& operator = (const Vector&);
  Vector& operator = (Vector&&);
};

std::istream& operator >> (std::istream& in, Vector& vec);
std::ostream& operator << (std::ostream& out, Vector& vec);

Vector operator + (Vector& vec1, Vector& vec2);

#endif
