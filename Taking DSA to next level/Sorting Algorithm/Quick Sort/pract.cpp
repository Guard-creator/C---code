#include <iostream>

int partition(int arr[], int low, int high) {

  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; j++) {
    if(arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i + 1], arr[high]);
  return i + 1;

}

void quickSort(int arr[], int low, int high) {

  if(low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }

}

int main() {

  int arr[] = {6, 3, 2, 7, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);
  
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}