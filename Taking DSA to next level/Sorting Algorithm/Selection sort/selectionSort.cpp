#include <iostream>

// Selection Sort works by repeatedly selecting the minimum element from 
// the unsorted part of the array and putting it at the beginning.

void selectionSort(int arr[], int n) {
  
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    // Find the index of the minimum element
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    // Swap if a smaller element was found
    if (minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }
  }

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  } 

}


int main() {

  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);
  
  return 0;
}