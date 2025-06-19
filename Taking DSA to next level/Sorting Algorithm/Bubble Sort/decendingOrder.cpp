#include <iostream>

// this is just in desending order 
// and use function of swap

void sortDesendingOrder(int arr[], int n) {

  for(int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] < arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if(!swapped) {
      break;
    }
  }

  std::cout << "Sort in Desending Order: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}

int main() {

  int arr[] = {4, 3, 6, 1, 2, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  sortDesendingOrder(arr, n);

  return 0;
}