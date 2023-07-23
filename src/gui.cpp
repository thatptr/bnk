#include <iostream>
#include <string>

#include "../include/bank.hpp"

template <typename T>
static void println(const T& a) {
  std::cout << a << std::endl;
}

template <typename T>
static void print(const T& a) {
  std::cout << a;
}

std::string input() {
  std::string a;
  std::cin >> a;
  return a;
}

namespace bnk {
// Setup a bank
combank setup_bank() {
  print("Amount the bank should start with: ");
  int b = std::stoi(input().c_str());

  combank out(b);

  return out;
}

// Show bank info
void bank_info(combank& a) {
  println("Capital: " + std::to_string(a.get_capital()));
  println("Customers: " + std::to_string(a.get_customers()));
}

// Add a customer
int add_customer(combank& a) {
  print("Capital: ");
  int b = std::stoi(input());

  int c = a.add_to_customers("", b);
  print("Created account with id of: " + std::to_string(c));

  return c;
}
// Remove a customer
void remove_customer(combank& a) {
  print("ID: ");
  int b = std::stoi(input().c_str());

  a.remove_customer(b);
  print("Removed account with id of: " + std::to_string(b));
}

}  // namespace bnk
