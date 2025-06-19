#include <iostream>
#include <vector>

// small topic but here it is 
// you can also use vector to in for loop using iterator
// with end and begin function

int main() {

  std::vector<int> vec = {2, 4, 6, 8, 10};

  // we need a iterator
  // we can make a iterator like this
  // std::vector<int>::iterator it;
  // but it get's confusing in loop for me or others
  // you can use auto instead modern feature of C++;

  for(auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << '\n';

  // you can also used another feature to make it reverse

  for(auto it = vec.rbegin(); it != vec.rend(); it++) {
    std::cout << *it << " ";
  }

  return 0;
}