#include <iostream>

int searchString(std::string names[], int size, std::string target) {

  for(int i = 0; i < size; i++) {
    
    if(names[i] == target) {
      return i;
    }
  }

  return -1;
}

int main() {

  std::string names[] = {"Alice", "Bob", "Charlie", "Dave"};
  int size = sizeof(names) / sizeof(names[0]);
  std::string target = "Charlie";

  int result = searchString(names, size, target);

  if(result != -1) {
    std::cout << target << " is found at index " << result << '\n';
  }

  return 0;
}