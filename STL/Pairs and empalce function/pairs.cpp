#include <iostream>

// a pair is a container from the Standard Template Library (STL) 
// that holds two values of possibly different types. It is defined 
// in the <utility> header.
// this library also exist in iostream but for practice we use utility
// in this case we dont use it

// pair we be use alot in data structure and algorithm

int main() {

  std::pair<int, std::string> pai = {56, "Hello"};

  std::cout << pai.first << '\n';
  std::cout << pai.second << '\n';

  std::cout << "+++++++++++++++++++++++++++++" << '\n';
  std::cout << "+++++++++++++++++++++++++++++" << '\n';
  
  // pair in a pair

  std::pair<std::pair<double, char>, std::pair<int, bool>> abe = {{56, 'B'}, {67, true}};

  std::cout << abe.first.first << '\n';
  std::cout << abe.first.second << '\n';
  std::cout << abe.second.first << '\n';
  std::cout << abe.second.second << '\n';

  // Pairs are compared lexicographically (first first, then second).

  std::cout << "+++++++++++++++++++++++++++++" << '\n';
  std::cout << "+++++++++++++++++++++++++++++" << '\n';

  std::pair<int, int> pair1 = {4, 6};
  std::pair<int, int> pair2 = {8, 2};

  std::cout << (pair1 < pair2) << '\n';

  return 0;
}

// Used for grouping related data.
// Efficient for small, heterogeneous data.
// Fundamental to many STL operations (e.g., map entries).