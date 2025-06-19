#include <iostream>

// we increament i to 2 so it only check the even numbers

void evenSort(int arr[], int n) {

  for(int i = 0; i < n - 1; i+=2) {

    int minIndex = i;
    for(int j = i + 2; j < n; j+=2) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    if(minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }
  }

}

int main() {

  int arr[] = {4, 99, 2, 88, 1, 77, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  evenSort(arr, n);

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  
  return 0;
}