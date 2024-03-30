#include <iostream>
#include <string>


class PrimeNumberException : public std::invalid_argument {
protected:
  std::string message;
public:
  PrimeNumberException(const std::string& message, const std::string msg = "") : std::invalid_argument(msg) {
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
  // PrimeNumber() = delete;
  // ~PrimeNumber();
  PrimeNumber(int value) {
    for (int i = 2; i * i <= value; ++i) {
      if (value % i == 0) {
        throw PrimeNumberException("The number " + std::to_string(value) + " is not a prime number");
      }
    }
    this->value = value;
  }
  int getValue() const  {
    return value;    
  }
};

std::ostream& operator<<(std::ostream& out, const PrimeNumber& primeNumber) {
  out << primeNumber.getValue() << std::endl;
  return out;
}

//  g++ source/lab6/lab6.cpp -o build/lab6

int main() {
  try {
    PrimeNumber p1(11);
    std::cout << p1 << std::endl;


    PrimeNumber p2(10);
    std::cout << p2 << std::endl;
  } catch (const PrimeNumberException& ex) {
    std::cout << ex.getMessage() << std::endl;
  }
  return 0;
}
