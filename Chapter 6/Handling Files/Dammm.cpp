#include <iostream>
#include <fstream>

// you can also use fstream 
// fstream is used for writing and reading in the same object

// fstream can read & write, but by default, it only opens in std::ios::in mode (read mode).
// If you don’t specify std::ios::out, fstream will not allow writing.
// If you don’t specify std::ios::in, fstream will not allow reading.
// also trunc is used when file is not created so it automatically create the file
// it's is also same as append but append keep the previous data

// fstream alone opens the file only in read mode.

int main() {

  // When you open a file using fstream in read & write mode (std::ios::in | std::ios::out), 
  // it actually maintains two separate pointers:
  // 1️⃣ Write Pointer (put pointer / seekp) → Controls where data is written
  // 2️⃣ Read Pointer (get pointer / seekg) → Controls where data is read

  std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::trunc);

  std::string userInput;
  std::cout << "Enter anything: ";
  std::getline(std::cin, userInput);
  file << userInput;
  file.seekg(0);

  // what is the purpose of seekg 
  // when using fstream the read pointer means where it should read from 
  // get's read from to the end of file 
  // means when a 100 page book have something written on the 1st page
  // its doesn't read from 1st page it read from 100 page 
  // Why 
  // When you write to the file, the write pointer (seekp) moves to the end of what was written.
  // However, the read pointer (seekg) does not automatically reset to the beginning.

  std::string userOutput;
  std::getline(file, userOutput);
  std::cout << userOutput << '\n';

  file.close();

  return 0;
}