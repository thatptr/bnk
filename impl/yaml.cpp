#include "../include/yaml.hpp"

namespace bnk {
void yaml::add_to_yaml(std::vector<std::string> arr) {
  YAML::Emitter out(this->outfile);  // Create an empty map to store the
                                     // key-value pairs from the input array
  std::map<std::string, std::string> map;

  // Iterate over the elements of the input array in pairs
  for (int i = 0; i < arr.size(); i += 2) {
    // Use the first element of each pair as the key and the second element as
    // the value in the map
    map[arr[i]] = arr[i + 1];
  }

  // Output the map in YAML format to the stream that the YAML emitter is
  // calling
  out << YAML::BeginMap;
  for (auto const& x : map) {
    out << YAML::Key << x.first;
    out << YAML::Value << x.second;
  }
  out << YAML::EndMap;
}
}  // namespace bnk
