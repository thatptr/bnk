#include <cstdlib>
#include <random>

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

  return rand_num;
}
}  // namespace bnk
