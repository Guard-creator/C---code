#include <iostream>
#include <map>

// In C++, a map is a container from the Standard Template Library (STL) that stores 
// elements in key-value pairs. Each key is unique, and it automatically sorts the elements 
// by the key (by default in ascending order using the < operator).

int main() {

  std::map<std::string, int> student;

  student["basit"] = 18;
  student["guard"] = 148;
  student["mw"] = 1445;

  // print the value when insert key
  std::cout << student["basit"] << '\n';

  for(auto p : student) {
    std::cout << p.first << ", " << p.second << '\n';
  }

  std::cout << '\n';

  if(student.find("basit") != student.end()) {
    std::cout << "Found\n";
  } else {
    std::cout << "Not found\n";
  }

  return 0;
}