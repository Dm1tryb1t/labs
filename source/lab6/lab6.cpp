#include <iostream>
#include <string>

class PrimeNumberException : std::invalid_argument {
// protected:
  std::string message;
public:
  PrimeNumberException(std::string message) : std::invalid_argument(message) {
    this->message = message;
  }
  std::string getMessage() const {
    return message;
  }
};

class PrimeNumber {
protected:
  int value;

public:
  PrimeNumber(int value) {
    isPrime();
    this->value = value;
  }
  void isPrime() const {
    for (int i = 2; i * i <= value; ++i) {
      if (value % i == 0) {
        throw PrimeNumberException(std::to_string(value) + " is not a prime number.");
      }
    }
  }
  int getValue() const  {
    return value;    
  }
};

std::ostream& operator<<(std::ostream& out, const PrimeNumber& primeNumber) {
  try {
    out << primeNumber.getValue() << std::endl;
  } catch (const PrimeNumberException& e) {
    out << "Error: " << e.getMessage() << std::endl;
  }
  return out;
}

//  g++ source/lab6/lab6.cpp -o build/lab6

int main() {
  PrimeNumber p1(10),  p2(5);
  // int qq = p1.getValue();
  p1 = 7;
  std::cout << p1;
  std::cout << p2;
  return 0;
}
