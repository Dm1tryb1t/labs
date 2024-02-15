#include <iostream>
#ifndef SMARTPTR_H
#define SMARTPTR_H


class Point {
  int x, y;
public:
  Point(int x, int y) : x(x), y(y) {}
  void print_info(std::ostream& out) const { 
    out << "(" << x << ", " << y << ")\n";
  }
};

template<class T>
class MyUnique_ptr {
  T* ptr = nullptr;
public:
  MyUnique_ptr(T*);
  ~MyUnique_ptr();

  T* get() const;
  
  T& operator*(); 
  T* operator->();
};

template<class T>
MyUnique_ptr<T>::MyUnique_ptr(T* ptr) {
  this->ptr = ptr;
  std::cout << "MyUnique_ptr\n";
}
template<class T>
MyUnique_ptr<T>::~MyUnique_ptr() {
  // std::cout << "~MyUnique_ptr\n";
  if (ptr) delete ptr;
  std::cout << "~MyUnique_ptr\n";
  // this = nullptr;
}

template<class T>
T* MyUnique_ptr<T>::get() const {
  return ptr;
}

template<class T>
T& MyUnique_ptr<T>::operator*() {
  /* if (ptr) */ return *ptr;
}
template<class T>
T* MyUnique_ptr<T>::operator->() {
  return ptr;
}

template<class T>
void Make_MyUnique(const T& x)
{
	MyUnique_ptr<T> ptr(new T(x));
  x.print_info(std::cout);
}

template<class T, class...Args>
void Make_MyUnique(const T& x, const Args&... args) {
	MyUnique_ptr<T> ptr(new T(x));
  x.print_info(std::cout);
  Make_MyUnique(args...);
}

template<class T>
class shared_ptr {

};

#endif
