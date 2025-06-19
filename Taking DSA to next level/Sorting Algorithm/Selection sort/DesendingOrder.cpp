#include <iostream>

// selection sort with desending order

void selectionSort(int arr[], int n) {

  for(int i = 0; i < n - 1; i++) {

    int maxIndex = i;

    for(int j = i + 1; j < n; j++) {
      if(arr[j] > arr[maxIndex]) {
        maxIndex = j;
      }
    }

    if(maxIndex != i) {
      std::swap(arr[i], arr[maxIndex]);
    }

  }

}

int main() {

  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  
  return 0;
}