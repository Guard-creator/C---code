#include <iostream>

void recursionSort(int arr[], int n) {

  if(n <= 1) return;

  recursionSort(arr, n - 1);

  int key = arr[n - 1];
  int j = n - 2;

  while(j >= 0 && arr[j] > key) {
    arr[j + 1] = arr[j];
    j--;
  }

  arr[j + 1] = key;

}
 
int main() {

  int arr[] = {5, 7, 3, 2, 6, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  recursionSort(arr, n);

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}