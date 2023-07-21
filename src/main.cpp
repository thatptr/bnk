#include <iostream>
#include <memory>

#include "../include/bank.hpp"

template <typename T>
void println(T a) {
  std::cout << a << std::endl;
}

int main() {
  std::unique_ptr<bnk::bank> a = std::make_unique<bnk::bank>(100);
  println(a->add_to_customers("Nyasha Smith", 100));
  println(a->get_capital());
  println(a->get_customers());
}
