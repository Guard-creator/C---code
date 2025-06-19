#include <iostream>

// just printing stars instead of numbers

void selectionSort(int arr[], int n) {

  for(int i = 0; i < n - 1; i++) {

    int minIndex = i;

    for(int j = i + 1; j < n; j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    if(minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }
  }

  std::cout << "Sort Array Star: ";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < arr[i]; j++) {
      std::cout << "*";
    }
    std::cout << " ";
  }
  std::cout << '\n';

}


int main() {

  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);

  return 0;
}