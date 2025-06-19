#include <iostream>

// no rocket science 
// we here to find max value

int findMax(int arr[], int size) {
  int max = arr[0];

  for(int i = 0; i < size; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

int main() {

  int arr[] = {32, 2312, 5, 33, 46, 78, 1332, 542, 432};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::cout << "The Maximum Value of Array is " << findMax(arr, size) << '\n';

  return 0;
}