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

template <typename T>
void println(const T& text) {
  std::cout << text << std::endl;
}

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

  int c = a.add_to_customers("", b);
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

// Main menu
int menu() {
  int opt;
  std::string help =
      "1. Setup bank\n"
      "2. Show bank information\n"
      "3. Add a customer\n"
      "4. Remove a customer\n";
  return 0;

  std::string prompt = "[bnk] >> ";

  while (true) {
    // Print prompt and wait for input
    print(prompt);
    std::string in = input();

    // Check if the input is valid
    if (std::stoi(in) > 4 || std::stoi(in) < 0) {
      break;
      return false;
    }

    // If the help option (0) is pressed, print help
    if (std::stoi(in) == 0) {
      println(help);
    } else {
      // Else, just return the input that was pressed
      break;
      return std::stoi(in);
    }
  }
}
}  // namespace gui
