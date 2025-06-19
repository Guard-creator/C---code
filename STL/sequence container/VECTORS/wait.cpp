#include <iostream>
#include <vector>

int main() {

  std::vector<int> numbers = {5, 6, 78, 64, 34, 8};

  for (auto it = numbers.begin(); it != numbers.end(); it++) {
    std::cout << *it << " ";  
  }

  // begin and end function are used for vector and mostly used to 
  // iterate over vector begin means first element numbers[0] 5
  // and end means last element numbers[6] 8 
  // and we use reference to display because if we print out directly
  // it we cause error and beause ther are iterator 
  // Iterators are not values; they are memory addresses 
  // think iterator like pointer
  /*
    int arr[] = {1, 2, 3};
    int* ptr = arr;  // ptr points to arr[0]
    std::cout << *ptr;  // ✅ Output: 1
  */

  return 0;
}