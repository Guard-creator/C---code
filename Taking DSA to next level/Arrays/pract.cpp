#include <iostream>

// here use pair to get both max and min in same function 

std::pair<int, int> findMaxMin(int arr[], int size) {

  int max = arr[0];
  int min = arr[0];

  for(int i = 0; i < size; i++) {
    if(max < arr[i]) max = arr[i];
    if(min > arr[i]) min = arr[i];
  }

  return {max, min};
}

int main() {

  int arr[] = {42, 17, 23, 56, 3, 89, 12};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::pair<int, int> result = findMaxMin(arr, size);

  std::cout << "Max " << result.first << ", Min: " << result.second << '\n';

  return 0;
}