#include <iostream>

// using recursion to sort 

void recursionSort(int arr[], int start, int n) {

  if(start >= n - 1) return;

  int minIndex = start;
  for(int i = start + 1; i < n; i++) {
    if(arr[i] < arr[minIndex]) {
      minIndex = i;
    }
  }
  
  std::swap(arr[start], arr[minIndex]);

  recursionSort(arr, start + 1, n);
}

int main() {

  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  recursionSort(arr, 0, n);

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  
  return 0;
}