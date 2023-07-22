#include <assert.h>

#include <map>
#include <memory>
#include <random>

#include "files.hpp"

namespace bnk {
class bank {
 protected:
  int capital;
  std::unique_ptr<files::file> f = std::make_unique<files::file>("bank.txt");
  std::map<int, int> customers;
  int customers_num;

 public:
  int get_capital();

  bank(int capital) {
    this->capital = capital;
    this->f->create_file();
    this->f->write_to_file("Bank set up with capital of " +
                           std::to_string(this->get_capital()));
  }

  int get_customers();

  int add_to_customers(std::string name, int capital);
};

class combank : private bank {
 public:
  bool deposit(int amount, int id);
  int withdraw(int amount, int id);
};
}  // namespace bnk
