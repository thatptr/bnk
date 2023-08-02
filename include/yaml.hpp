#include <yaml-cpp/yaml.h>

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace bnk {

class yaml {
private:
  std::string name;
  YAML::Node file;
  std::ofstream outfile{this->name};

public:
  yaml(std::string name) {
    // Setting the name
    this->name = name;

    // Setting up the file
    file = YAML::LoadFile(this->name);
  }
  
protected:
  // Adding key values
  void add(std::vector<std::string> arr);

  // Removing key values
  std::string *output(std::string key);

  // Parsing yaml file
  std::map<std::string, std::string>
  parse_yaml_file(const std::string &filename);
};
} // namespace bnk
