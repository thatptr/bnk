#include "../include/yaml.hpp"
#include <vector>

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

// Parse a yaml file
std::map<std::string, std::string>
yaml::parse_yaml_file(const std::string &filename) {
  try {
    // Load the file
    YAML::Node root = YAML::LoadFile(filename);

    // Make a result map
    std::map<std::string, std::string> result;
    for (const auto &node : root) {
      result[node.first.as<std::string>()] = node.second.as<std::string>();
    }

    return result;
  } catch (const YAML::Exception &e) {
    std::cerr << "Error parsing YAML file: " << e.what() << std::endl;
    return {};
  }
}
} // namespace bnk
