#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

#ifndef SMARTPTR_H
#define SMARTPTR_H

template<class T>
class MyUnique_ptr {
  T* ptr = nullptr;
public:
	explicit MyUnique_ptr(T* ptr = nullptr) : ptr(ptr) {}
	MyUnique_ptr(const MyUnique_ptr<T>& other) = delete;
	MyUnique_ptr(MyUnique_ptr<T>&& other) noexcept : ptr(other.ptr) {
			other.ptr = nullptr;
	}
	~MyUnique_ptr() {
		if (ptr) {
			delete ptr;
			std::cout << "Delete unique pointer\n";
		}
	}

	T* get() const {
		return ptr;
	}

	T& operator*() const {
		return *ptr;
	}

	T* operator->() const {
		return ptr;
	}

	MyUnique_ptr& operator=(const MyUnique_ptr<T>&) = delete;

	MyUnique_ptr& operator=(MyUnique_ptr<T>&& other) noexcept {
		if (this != &other) {
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		return *this;
	}
};

template<class T>
std::ostream& operator<<(std::ostream& out, const MyUnique_ptr<T>& ptr) {
  return out << *ptr;
}

template <class T>
void create_uniqueqq(std::vector<MyUnique_ptr<T>>& vec, const T& t) {
  vec.push_back(MyUnique_ptr<T>(new T(t)));
}

template <class T>
MyUnique_ptr<T> create_unique(const T& t) {
  return MyUnique_ptr<T>(new T(t));
}

template <class T, class ...Args>
void create_uniqueqq(std::vector<MyUnique_ptr<T>>& vec, const T& t, const Args& ... args) {
  vec.push_back(MyUnique_ptr<T>(new T(t)));
  create_uniqueqq(vec, args...);
}

template <class T, class ...Args>
std::vector<MyUnique_ptr<T>> create_unique(const T& t, const Args& ... args) {
	std::vector<MyUnique_ptr<T>> vec;
	create_uniqueqq(vec, t, args...);
	return vec;
}

template<class T>
class MyShared_ptr {
	T* ptr = nullptr;
	size_t* ptr_count = nullptr;
public:
	explicit MyShared_ptr(T* ptr = nullptr) : ptr(ptr), ptr_count(ptr ? new size_t(1) : nullptr) {}

	MyShared_ptr(const MyShared_ptr& other) : ptr(other.ptr), ptr_count(other.ptr_count) {
		if (ptr) {
			++(*ptr_count);
		}
	}

	MyShared_ptr(MyShared_ptr&& other) noexcept : ptr(other.ptr), ptr_count(other.ptr_count) {
		other.ptr = nullptr;
		other.ptr_count = nullptr;
	}

	~MyShared_ptr() {
		if (ptr_count && --(*ptr_count) == 0) {
			delete ptr;
			delete ptr_count;
			std::cout << "Delete shared pointer\n";
		}
	}

	size_t get_ptrCount() const {
		return ptr_count ? *ptr_count : 0;
	}

	T* get() const {
		return ptr;
	}

	T& operator*() const {
		return *ptr;
	}

	T* operator->() const {
		return ptr;
	}

	MyShared_ptr& operator=(const MyShared_ptr& other) {
		if (this != &other) {
			if (ptr_count && --(*ptr_count) == 0) {
				delete ptr;
				delete ptr_count;
			}
			ptr = other.ptr;
			ptr_count = other.ptr_count;
			if (ptr) {
				++(*ptr_count);
			}
		}
		return *this;
	}

	MyShared_ptr& operator=(MyShared_ptr&& other) noexcept {
		if (this != &other) {
			if (ptr_count && --(*ptr_count) == 0) {
				delete ptr;
				delete ptr_count;
			}
			ptr = other.ptr;
			ptr_count = other.ptr_count;
			other.ptr = nullptr;
			other.ptr_count = nullptr;
		}
		return *this;
	}
};

template<class T>
std::ostream& operator<<(std::ostream& out, const MyShared_ptr<T>& ptr) {
	return out << *ptr;
}

template <class T>
void create_sharedqq(std::vector<MyShared_ptr<T>>& vec, const T& t) {
	vec.push_back(MyShared_ptr<T>(new T(t)));
}

template <class T>
MyShared_ptr<T> create_shared(const T& t) {
	return MyShared_ptr<T>(new T(t));
}

template <class T, class ...Args>
void create_sharedqq(std::vector<MyShared_ptr<T>>& vec, const T& t, const Args& ... args) {
	vec.push_back(MyShared_ptr<T>(new T(t)));
	create_sharedqq(vec, args...);
}

template <class T, class ...Args>
std::vector<MyShared_ptr<T>> create_shared(const T& t, const Args& ... args) {
	std::vector<MyShared_ptr<T>> vec;
	create_sharedqq(vec, t, args...);
	return vec;
}

#endif
