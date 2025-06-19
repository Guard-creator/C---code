#include <iostream>
#include <set>

int main() {

  std::set<int> set1 = {1, 2, 3, 4};
  std::set<int> set2 = {3, 4, 5, 6};

  std::set<int> set3;

  for(int num : set1) {
    if(set2.find(num) != set2.end()) {
      set3.insert(num);
    }
  }

  std::cout << "Result: ";
  for(int s : set3) {
    std::cout << s << " ";
  }

  return 0;
}
