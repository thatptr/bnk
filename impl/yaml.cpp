#include "../include/yaml.hpp"
#include <vector>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/parse.h>

namespace bnk {
void yaml::add(std::vector<std::string> arr) {
  YAML::Emitter out(this->outfile); // Create an empty map to store the
                                    // key-value pairs from the input array
  std::map<std::string, std::string> map;

  // Iterate over the elements of the input array in pairs
  for (int i = 0; i < (int)arr.size(); i += 2) {
    // Use the first element of each pair as the key and the second element as
    // the value in the map
    map[arr[i]] = arr[i + 1];
  }

  // Output the map in YAML format to the stream that the YAML emitter is
  // calling
  out << YAML::BeginMap;
  for (auto const &x : map) {
    out << YAML::Key << x.first;
    out << YAML::Value << x.second;
  }
  out << YAML::EndMap;
}

// Ouput the file in an array
std::string *yaml::output(std::string key) {
  // Load the file
  YAML::Node config = YAML::LoadFile(this->name);

  // Setting the array where things are gonna go
  std::vector<std::string> out;
}
} // namespace bnk
