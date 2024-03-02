#include "Hardware_and_software_protection.h"

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
  MyUnique_ptr(T* ptr) : ptr(ptr) { std::cout << "MyUnique_ptr\n"; }
  ~MyUnique_ptr() {
    // std::cout << "~MyUnique_ptr\n";
    if (ptr) delete ptr;
    ptr = nullptr;
    // std::cout << "~MyUnique_ptr\n";
  }

  T* get() const {
    return ptr;
  }
  
  T& operator*() {
    /* if (ptr) */ return *ptr;
  }
  T* operator->() {
    return ptr;
  }

  MyUnique_ptr<T> operator = (const MyUnique_ptr<T>&) {
    throw std::exception("Copy is restricted\n");
  }
  MyUnique_ptr<T>& operator = (MyUnique_ptr<T>&& other) {
    if (this == other) return this;
    if (ptr) delete ptr;
    ptr = nullptr;
    std::swap(ptr, other.ptr);
    return this;
  }
};


// Хуита == Исправить:

/*template<class T>
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
}*/

template<class T>
class MyShared_ptr {
  T* ptr = nullptr;
public:
  MyShared_ptr(T* ptr) : ptr(ptr) { std::cout << "MyUnique_ptr\n"; }
  ~MyShared_ptr() {
    // std::cout << "~MyUnique_ptr\n";
    if (ptr) delete ptr;
    ptr = nullptr;
    // std::cout << "~MyUnique_ptr\n";
  }

  T* get() const {
    return ptr;
  }
  
  T& operator*() {
    /* if (ptr) */ return *ptr;
  }
  T* operator->() {
    return ptr;
  }

  MyShared_ptr<T> operator = (const MyShared_ptr<T>& other) {
    ptr = other.ptr;
  }
  MyShared_ptr<T>& operator = (MyShared_ptr<T>&& other) {
    if (this == other) return this;
    if (ptr) delete ptr;
    ptr = nullptr;
    std::swap(ptr, other.ptr);
    return this;
  }
};


// Хуита == Исправить:

/*template<class T>
void Make_MyShared(const T& x)
{
	MyShared_ptr<T> ptr(new T(x));
  x.print_info(std::cout);
}

template<class T, class...Args>
void Make_MyShared(const T& x, const Args&... args) {
	MyShared_ptr<T> ptr(new T(x));
  x.print_info(std::cout);
  Make_MyUnique(args...);
}*/

#endif
