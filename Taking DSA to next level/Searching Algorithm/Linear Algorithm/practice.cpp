#include <iostream>
#include <vector>

// Find all indices of a number

std::vector<int> findit(int arr[], int size, int target) {

  std::vector<int> vec;

  for(int i = 0; i < size; i++) {
    if(arr[i] == target) {
      vec.push_back(i);
    }
  }

  return vec;
}

int main() {

  int arr[] = {5, 3, 7, 3, 9, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 3;

  std::vector<int> vec = findit(arr, size, target);

  if(!vec.empty()) {
    std::cout << target << " is found in: ";
    for(int element : vec) {
      std::cout << element << ", ";
    }
  } else {
    std::cout << "Vector is Empty.\n";
  }

  return 0;
}