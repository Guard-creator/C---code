#include <iostream>
#include <vector>

void insertionSort(int arr[], int n) {

  // Start from the second element (index 1) because
  // a single element is always "sorted" by itself
  for(int i = 1; i < n; i++) {

    // Store the current value in 'key' so we don’t lose it while shifting
    int key = arr[i];

    // Start comparing with the previous elements
    int j = i - 1;

    // This loop shifts all elements greater than 'key' one position ahead
    // It keeps moving backward as long as:
    // 1. We're within bounds (j >= 0)
    // 2. arr[j] is greater than key (meaning out of order)
    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j]; // Shift the element to the right
      j--;                 // Move to the previous element
    }

    // When loop ends, j is at the correct position before where key should go
    // Insert the key at its correct sorted position
    arr[j + 1] = key;
  }

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}


int main() {

  int arr[] = {5, 3, 4, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  return 0;
}