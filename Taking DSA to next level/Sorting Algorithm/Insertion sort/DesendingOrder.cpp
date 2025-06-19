#include <iostream>

// doing insertion sort ins decending Order

void insertionSort(int arr[], int n) {

  for(int i = 1; i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;

  }

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}
 
int main() {

  int arr[] = {10, 3, 5, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  return 0;
}