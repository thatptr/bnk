#include <iostream>
#include <string>

namespace files {
class file {
 public:
  std::string get_file_name();

  void write_to_file(std::string text);

  void delete_from_file(std::string text);

  void delete_line_from_file(int line);

  std::string get_encrypted_file();

 private:
  std::string file_name;

  std::string password;
};
}  // namespace files
