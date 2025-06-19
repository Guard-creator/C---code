#include <iostream>

// if target is not found but it return the index of 
// where the target in sorted array should exist if it's in array

int searchInsertionPostion(int arr[], int size, int target, bool& found) {

  int low = 0;
  int high = size;

  while(low < high) {

    int mid = low + (high - low) / 2;

    if(arr[mid] < target) {
      low = mid + 1;
    } else if(arr[mid] >= target){
      high = mid;
    }

  }

  if (low < size && arr[low] == target) {
      found = true;
      return low;
  } else {
      found = false;
      return low;
  }

  
}

int main() {

  int arr[] = {1, 3, 5, 10};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 1;
  bool found = false;

  int result = searchInsertionPostion(arr, size, target, found);

  if (found) {
    std::cout << target << " found at index " << result << '\n';
  } else {
    std::cout << target << " not found but if insert in sorted array the position our target will hold " << result;
  }

  return 0;
}