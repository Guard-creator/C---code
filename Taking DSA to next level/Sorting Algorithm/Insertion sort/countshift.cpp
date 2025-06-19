#include <iostream>

// counting how many times element shift 
// arr[j+1] = arr[j];

void sort(int arr[], int n) {

  int shift = 0;

  for(int i = 1; i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      shift++;
      j--;
    }

    arr[j + 1] = key;

  } 

  std::cout << "Shift: " << shift << '\n';
  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}

int main() {

  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, n);

  return 0;
}