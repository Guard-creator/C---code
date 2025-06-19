#include <iostream>
#include <set>

int main() {

  // finding missing number in order

  // imagine if that one number is missing means 
  // the size n will have one number add
  // to complete it size;

  std::set<int> s = {3, 2, 1, 5};
  int size = s.size() + 1; // one is added because of the missing number 

  for(int i = 1; i < size; i++) {
    if(s.find(i) == s.end()) {
      std::cout << "Missing number is " << i << '\n';
      break;
    }
  }

  return 0;
}