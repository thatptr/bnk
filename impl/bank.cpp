#include "../include/bank.hpp"

#include <cstdlib>
#include <random>
#include <string>

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
int bank::add_to_customers(int capital) {
  int rand_num = randint(10000);  // generate a random integer between 0 and 99
  this->customers.insert(
      {rand_num, capital});  // use the random integer as a key when inserting a
                             // new customer
  ++this->customers_num;

  this->f->write_to_file("Added customer with ID - " +
                         std::to_string(rand_num));

  return rand_num;
}

// Remove a customer
bool bank::remove_customer(int id) {
  // Check if the we can find the customer, if not, just return false;
  if (this->customers.find(id) == this->customers.end()) return false;

  // If we can, decrease the customer num value and erase its id
  --this->customers_num;
  this->customers.erase(id);

  // We now up the file and return tue
  this->f->write_to_file("Removed customer with ID - " + std::to_string(id));
  return true;
}

// Deposit
bool combank::deposit(int amount, int id) {
  // Check if the we can find the customer, if not, just return false;
  if (customers.find(id) == customers.end()) return false;

  // If true; add the amount in the account and update the file
  this->customers[id] += amount;
  this->f->write_to_file("ID: " + std::to_string(id) + " added " +
                         std::to_string(amount) + " to their account");
  return true;
}

// Withdraw
int combank::withdraw(int amount, int id) {
  // Check if the we can find the customer, if not, just return false;
  if (customers.find(id) == customers.end()) return false;

  // If we can, remove the money in the account
  this->f->write_to_file("ID: " + std::to_string(id) + " removed " +
                         std::to_string(amount) + " from their account");
  this->customers[id] -= amount;

  // Return the amount left
  return this->customers[id];
}

// Get customer's capital
int bank::get_customer_capital(int id) {
  // Check if the we can find the customer, if not, just return false;
  if (customers.find(id) == customers.end()) {
    return false;
  } else {
    // If we can, return the customer's id
    return this->customers[id];
  }
}
}  // namespace bnk
