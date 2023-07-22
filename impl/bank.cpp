#include <cstdlib>
#include <random>
#include <string>

#include "../include/bank.hpp"

namespace bnk {
int bank::get_capital() { return this->capital; }

int bank::get_customers() { return this->customers_num; }

// Get random interger
static int randint(int n) {
  std::random_device rd;   // obtain a random number from hardware
  std::mt19937 gen(rd());  // seed the generator
  std::uniform_int_distribution<> distr(0, n - 1);  // define the range
  return distr(gen);                                // generate a random integer
}

// Add to customers
int bank::add_to_customers(std::string name, int capital) {
  int rand_num = randint(10000);  // generate a random integer between 0 and 99
  this->customers.insert(
      {rand_num, capital});  // use the random integer as a key when inserting a
                             // new customer
  ++this->customers_num;

  this->f->write_to_file("Added customer with ID - " +
                         std::to_string(rand_num));

  return rand_num;
}

// Deposit
bool combank::deposit(int amount, int id) {
  if (customers.find(id) == customers.end()) {
    return false;
  } else {
    this->customers[id] += amount;
    this->f->write_to_file("ID: " + std::to_string(id) + " added " +
                           std::to_string(amount) + " to their account");
    return true;
  }
}

// Withdraw
int combank::withdraw(int amount, int id) {
  if (customers.find(id) == customers.end()) {
    return false;
  } else {
    this->f->write_to_file("ID: " + std::to_string(id) + " removed " +
                           std::to_string(amount) + " from their account");
    this->customers[id] -= amount;
    return amount;
  }
}

// Get customer's capital
int bank::get_customer_capital(int id) {
  if (customers.find(id) == customers.end()) {
    return false;
  } else {
    return this->customers[id];
  }
}

}  // namespace bnk
