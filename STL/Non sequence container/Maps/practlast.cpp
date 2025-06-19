#include <iostream>
#include <map>
#include <vector>

int main() {

  std::vector<int> vec = {1, 2, 2, 3, 4, 1, 5};
  std::map<int, int> freq;
  
  for(auto pr : vec) {
    freq[pr]++;
  }

  std::cout << "Elements Only Appear Ones are: ";
  for(auto pr : freq) {
    if(pr.second == 1) {
      std::cout << pr.first << " ";
    }
  }

  return 0;
};