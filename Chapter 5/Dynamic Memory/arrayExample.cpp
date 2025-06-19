#include <iostream>

using string = std::string;

int main() {

  // see we didn't create a array name 
  // we create a pointer and use memory allocated 
  // or memory dynamic to assign how long will be the array or 
  // what it will contain. 

  string *pNames = nullptr;
  int size;

  std::cout << "Enter the Size of Array: \n";
  std::cin >> size;

  pNames = new string[size];

  for(int i = 0; i < size; i++) {
    std::cout << "Enter The Names you Want of #" << i + 1 << ": \n";
    std::cin >> pNames[i];
  }

  for(int i = 0; i < size; i++) {
    std::cout << pNames[i] << " ";
  }

  delete[] pNames; // we have to use square breacket to for deleting it to precent leak memory.

  return 0;
}