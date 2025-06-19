#include <iostream>
#include <map>
#include <vector>

int main() {

  std::vector<int> arr = {1, 3, 2, 3, 4, 3, 2, 1, 2};

  std::map<int, int> freq;

  for(auto element : arr) {
    freq[element]++;
  }

  int maxfrquency = -1;
  int maxcount = 0;

  for(auto pr : freq) {
    if(pr.second > maxcount) {
      maxcount = pr.second;
      maxfrquency =  pr.first;
    }
  }

  std::cout << "Most frequency is " << maxfrquency << " Appear " << maxcount << '\n';

  return 0;
}