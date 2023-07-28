#include "../include/files.hpp"

#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <string>

namespace files {

// Get file name
std::string file::get_file_name() { return this->file_name; }

// Check if file exits
bool file::check_file_exists(const std::string& file) {
  // Checks if we can access the c_str of file
  return (access(file.c_str(), F_OK) != 1);
}

// Write to file
bool file::write_to_file(const std::string& text) {
  // If the file doesnt exist, return false
  if (!this->check_file_exists(this->file_name)) return false;

  // Else; open the file in append mode
  std::ofstream f{this->file_name, std::ios::app};

  // Enter the text and close, returning true
  f << text << std::endl;
  f.close();
  return true;
}

// Delete line from a file
bool file::delete_line_from_file(const std::string& deleteline) {
  // If the file doesnt exist, return false
  if (!this->check_file_exists(this->file_name)) return false;

  // Line: the current line
  std::string line;

  // The final file
  std::fstream fin(this->file_name);

  // The temporary file
  std::fstream temp("temp");

  /* The process is:
   * Check if the current line the line requested for deletion
   * If false, skip
   * Else, replace the ine with an empty string, basically removing the file
   */
  while (getline(fin, line)) {
    line.replace(line.find(deleteline), deleteline.length(), "");
    temp << line << std::endl;
  }

  // Returns true
  return true;
}

// Creates a file in a specified directory
void file::create_file() { std::ofstream file{this->file_name}; }
}  // namespace files
