#include <assert.h>

#include <map>
#include <memory>
#include <random>

#include "files.hpp"

namespace bnk {
class bank {
 public:
  int get_capital();

  bank(int capital) {
    this->f->write_to_file("Bank set up with capital of " +
                           std::to_string(this->get_capital()));
    this->capital = capital;
  }

  int get_customers();

  int add_to_customers(std::string name, int capital);

 private:
  int capital;
  std::unique_ptr<files::file> f = std::make_unique<files::file>("bank.txt");
  std::map<int, int> customers;
  int customers_num;
};
}  // namespace bnk
