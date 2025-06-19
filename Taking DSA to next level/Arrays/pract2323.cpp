#include <iostream>
#include <algorithm>

// we sort the algorithm so now we know which one is the max and min 

int main() {

  int arr[] = {42, 17, 23, 56, 3, 89, 12};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::sort(arr, arr + size);

  std::cout << "Max: " << arr[size - 1] << " Min: " << arr[0] << '\n';

  return 0;
}