#include <iostream>

void sort(int arr[], int n) {

  for(int i = 0; i < n - 1; i++) {
    bool swapped = false;
      for(int j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          swapped = true;
        }
      }

      std::cout << "Pass " << i + 1 << ": ";
      for(int k = 0; k < n; k++) {
        std::cout << arr[k] << " ";
      }
      std::cout << '\n';

      if(!swapped) {
        break;
      }

  }

}

int main() {

  int arr[] = {4, 3, 6, 2, 1, 5, 7, 9, 10, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, n);

  return 0;
}