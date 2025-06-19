#include <iostream>

// this is also called first occurance

// Binary Search is used to search for an element in a sorted array by 
// repeatedly dividing the search interval in half.

/*
  ✅ Conditions:
The array must be sorted (ascending or descending).
If not sorted, you have to sort it first (which takes extra time).
*/

int binarySearch(int arr[], int size, int target) {

  int low = 0;
  int high = size - 1;

  while(low <= high) {

    // when we do high - low we get the distance then we divide it by 2 to get's it midlle part btw them 
    // then we add the low to get exactly where the elemet is 
    /*
    low = 4
    high = 6

    (high - low) = 2
    (2 / 2) = 1
    mid = 4 + 1 = 5

    high - low → how many elements between them
    Divide it by 2 → gives half the distance
    Add that to low → brings you to the middle

    */


    int mid = low + (high - low) / 2;

    if(arr[mid] == target) {
      return mid;
    } else if(arr[mid] < target) {
      low = mid + 1;
    } else if(arr[mid] > target) {
      high = mid - 1;
    }

  }

  return -1;
}

int main() {

  int arr[] = {3, 8, 15, 23, 42, 42, 42, 55, 78};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 8;

  int result = binarySearch(arr, size, target);

  if (result != -1) {
    std::cout << target << " found at index " << result << '\n';
  } else {
    std::cout << target << " not found.\n";
  }

  return 0;
}