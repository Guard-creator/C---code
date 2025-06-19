#include <iostream>

// “Find the first element that is greater than or equal to the target”

int lowerBound(int arr[], int size, int target) {
    
  int low = 0;
  int high = size - 1;

  while(low < high) {
    /*
      This means:
      Keep narrowing the range as long as there's more than one element left
      Because once low == high, we have only one position left — time to check it.
    */
    
    int mid = low + (high - low) / 2;

    // arr[mid] < target will help you go to right at index if target value 
    // is greater then arr[mid] means arrays middle term
    // is less then the target // and soo it move on to the right by setting low to mid + 1 

    // arr[mid] >= target will help you get to left side of the index
    // if target value is less then the middle term or equal to then
    // set the high to mid

    // only time this is end when low < high part become true

    if(arr[mid] < target) {
      low = mid + 1;
    } else if(arr[mid] >= target) {
      high = mid;
    }

    // but here if we find the equal value, that value may or
    // may not be first index of te value 
    // so we do high = mid 
    // so the value in the arr[] when searching stay there 

  }

    if (arr[low] >= target) return low;
    return -1;
}

int main() {
    int arr[] = {3, 5, 5, 5, 6, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int index = lowerBound(arr, size, target);

    if(index != -1) {
        std::cout << "Lower bound of " << target << " is at index " << index << " (value: " << arr[index] << ")\n";
    } else {
        std::cout << "No element >= " << target << " found.\n";
    }

    return 0;
}
