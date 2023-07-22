#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "../include/files.hpp"

namespace files {
// Get file name
std::string file::get_file_name() { return this->file_name; }

// Check if file exits
bool file::check_file_exists(const std::string& file) {
  return (access(file.c_str(), F_OK) != 1);
}

// Write to file
bool file::write_to_file(const std::string& text) {
  if (this->check_file_exists(this->file_name)) {
    std::ofstream f{this->file_name, std::ios::app};
    f << text << std::endl;
    f.close();
    return true;
  } else {
    return false;
  }
}

// Delete line from a file
bool file::delete_line_from_file(const std::string& deleteline) {
  std::string line;
  std::fstream fin(this->file_name);
  std::fstream temp("temp");

  if (this->check_file_exists(this->file_name)) {
    while (getline(fin, line)) {
      line.replace(line.find(deleteline), deleteline.length(), "");
      temp << line << std::endl;
    }
    return true;
  } else {
    return false;
  }
}

void file::create_file() { std::ofstream file{this->file_name}; }

}  // namespace files
