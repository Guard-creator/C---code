#include <iostream>

// sorting only odd index in arr numbers
// and keep the rest of the element same 
// there is another method to do this 
// next file...

void sortOddIndexedElements(int arr[], int n) {

  for(int i = 1; i < n; i+=2) {
  int key = arr[i];
  int j = i - 2;

  while(j >= 0 && arr[j] > key) {
    arr[j + 2] = arr[j];
    j -= 2;
  }

  arr[j + 2] = key;
  }

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}

int main() {

  int arr[] = {10, 3, 5, 2, 4, 6, 8, 7, 9, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  sortOddIndexedElements(arr, n);

  return 0;
}
