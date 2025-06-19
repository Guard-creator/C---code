#include <iostream>

// it is used to find the last occurance of the target value 
// even if it is dublicate

int lastOccurance(int arr[], int size, int target) {

  int low = 0;
  int high = size - 1;
  int result = -1;

  while(low <= high) {

    int mid = low + (high - low) / 2;

    if(arr[mid] == target) {
      result = mid;
      low = mid + 1;
    } else if(arr[mid] < target) {
      low = mid + 1;
    } else if(arr[mid] > target) {
      high = mid - 1;
    }

  }

  return result;
}

int main() {

    int arr[] = {2, 4, 4, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int index = lastOccurance(arr, size, target);

    if(index != -1) {
        std::cout << "Last Occurance of " << target << " is at index " << index << " (value: " << arr[index] << ")\n";
    } else {
        std::cout << "No element > " << target << " found.\n";
    }

  return 0;
}