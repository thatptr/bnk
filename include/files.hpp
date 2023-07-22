#include <fstream>
#include <iostream>
#include <string>

namespace files {
class file {
 public:
  std::string get_file_name();

  bool write_to_file(const std::string& text);

  bool delete_line_from_file(const std::string& deleteline);

  std::string get_encrypted_file();

  void create_file();

  file(const std::string& file_name) { this->file_name = file_name; }

 private:
  std::string file_name;

  bool check_file_exists(const std::string& file);

  std::string password;
};
}  // namespace files
