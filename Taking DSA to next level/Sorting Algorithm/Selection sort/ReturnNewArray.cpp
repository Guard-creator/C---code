#include <iostream>

// returning an array using pointer

int* selectionSort(int arr[], int n) {

  int* sortedArray = new int[n];
  for(int i = 0; i < n; i++) {
    sortedArray[i] = arr[i];
  }

  for(int i = 0; i < n - 1; i++) {
    int minIndex = i;

    for(int j = i + 1; j < n; j++) {
      if(sortedArray[j] < sortedArray[minIndex]) {
        minIndex = j;
      }
    }

    if(minIndex != i) {
      std::swap(sortedArray[i], sortedArray[minIndex]);
    }
  }

  return sortedArray;
}

int main() {
  int arr[] = {7, 2, 5, 1, 9, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  int* sortedArr = selectionSort(arr, n);

  std::cout << "Original Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << '\n';

  std::cout << "Copy Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << sortedArr[i] << " ";
  }

  delete[] sortedArr;

  return 0;
}
