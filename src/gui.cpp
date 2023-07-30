#include <iostream>
#include <memory>
#include <string>

#include "../include/bank.hpp"

namespace gui {
static std::string input() {
  // Create a string and add input in it
  std::string a;
  std::cin >> a;
  return a;
}

// Helper function printing without a newline
template <typename T>
void println(const T& text) {
  std::cout << text << std::endl;
}

// Helper function printing without a newline
template <typename T>
void print(const T& text) {
  std::cout << text;
}

// Setup a bank
bnk::combank setup_bank() {
  print("Amount the bank should start with: ");
  int b = std::stoi(input().c_str());

  bnk::combank out(b);

  return out;
}

// Show bank info
void bank_info(bnk::combank& a) {
  println("Capital: " + std::to_string(a.get_capital()));
  println("Customers: " + std::to_string(a.get_customers()));
}

// Add a customer
int add_customer(bnk::combank& a) {
  print("Capital: ");
  int b = std::stoi(input());

  int c = a.add_to_customers(b);
  println("Created account with id of: " + std::to_string(c));

  return c;
}
// Remove a customer
void remove_customer(bnk::combank& a) {
  print("ID: ");
  int b = std::stoi(input().c_str());

  a.remove_customer(b);
  println("Removed account with id of: " + std::to_string(b));
}
}  // namespace gui
