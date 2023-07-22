#include <iostream>
#include <memory>

#include "../include/bank.hpp"

template <typename T>
void println(T a) {
  std::cout << a << std::endl;
}

int main() {
  std::unique_ptr<bnk::combank> a = std::make_unique<bnk::combank>(100);
  int id = a->add_to_customers("Nyasha Smith", 100);
  println(id);
  println(a->customers[id]);  // returns capital

  // Adding to capital
  a->deposit(100, id);

  println(a->customers[id]);

  // Removing from capital
  a->withdraw(50, id);

  println(a->customers[id]);

  println(a->get_customers());
}
