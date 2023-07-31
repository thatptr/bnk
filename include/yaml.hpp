#include <yaml-cpp/emitter.h>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/parse.h>
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

protected:
  yaml(std::string name) {
    // Setting the name
    this->name = name;

    // Setting up the file
    file = YAML::LoadFile(this->name);
  }

  // Adding key values
  void add(std::vector<std::string> arr);

  // Removing key values
  std::string *output(std::string key);
};
} // namespace bnk
