#include "smartPtr.h"
#include <memory>

template<class T>
MyUnique_ptr<T>::MyUnique_ptr(T* ptr) {
  this->ptr = ptr;
}
template<class T>
MyUnique_ptr<T>::~MyUnique_ptr() {
  if (this) delete this;
  this = nullptr;
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
