#include "../include/yaml.hpp"
#include "../include/files.hpp"
#include <string>
#include <memory>

namespace bnk {
  class account {
    std::unique_ptr<bnk::yaml> yaml_file = std::make_unique<bnk::yaml>(this->store);
    std::unique_ptr<files::file> raw_file = std::make_unique<files::file>(this->store);
    std::string store;
    std::string account_name;
    std::string password;

  public:
    account(std::string yaml_file){
      
    }
  };
} // namespace bnk
