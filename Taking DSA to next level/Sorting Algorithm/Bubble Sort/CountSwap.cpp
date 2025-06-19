#include <iostream>

// nothing special just counting swapped

void sort(int arr[], int n) {

  int swapCount = 0;

  for(int i = 0; i < n - 1; i++) {
    int swapped = false;
      for(int j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          swapped = true;
          swapCount++;
        }
      }
    if(!swapped) {
      break;
    }
  }

  std::cout << "Sorted Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n' << "Swap: " << swapCount << '\n';

}

int main() {

  int arr[] = {4, 3, 6, 2, 1, 5, 7, 9, 10, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, n);
  
  return 0;
}