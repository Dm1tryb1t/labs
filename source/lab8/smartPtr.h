
#ifndef SMARTPTR_H
#define SMARTPTR_H

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

#endif
