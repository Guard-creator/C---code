#include <iostream>
#include <list>

int main() {

  std::list<int> lis = {1, 2, 2, 4, 5, 6, 3, 3, 8, 8, 9, 9};

  lis.sort(); // sort the list
  lis.unique(); // remove the dublicates elements.

  for(int element : lis) {
    std::cout << element << " ";
  }

  return 0;
}
