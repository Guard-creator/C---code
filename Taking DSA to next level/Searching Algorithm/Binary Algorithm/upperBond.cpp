#include <iostream>

// Upper Bound is the index of the first element that is greater than the target in a sorted array.

int upperBond(int arr[], int size, int target) {

  int low = 0;
  int high = size - 1;

  // only thing matter is also this condition
  // this means if condition is false we have search the whole array
  while(low < high) {

    int mid = low + (high - low) / 2;

    // if arr[mid] <= target find a equal value it gonna skip it
    // because we want a value greater strictly.. 

    if(arr[mid] <= target) {
      low = mid + 1;
    } else if(arr[mid] > target) {
      high = mid;
    }

  }
  
  if(arr[low] > target) return low;
  return -1;
} 

int main() {

  int arr[] = {3, 5, 5, 5, 6, 7, 8, 10};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 8;

  int result = upperBond(arr, size, target);

  if(result != -1) {
    std::cout << target << " upperbond was found at index " << result << " Value: " << arr[result] << '\n';
  } else {
    std::cout << "Value was not found in array.\n";
  }

  return 0;
}