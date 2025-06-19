#include <iostream>

// we are using recursion to sort the array bubble sort



void recursionSwap(int arr[], int n) {

  if (n == 1) return;

  for(int i = 0; i < n - 1; i++) {
    if(arr[i] > arr[i + 1]) {
      std::swap(arr[i], arr[i + 1]);
    }
  }

  return recursionSwap(arr, n - 1);
}

int main() {
  
  int arr[] = {4, 3, 6, 2, 1, 5, 7, 9, 10, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  recursionSwap(arr, n);

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;

}