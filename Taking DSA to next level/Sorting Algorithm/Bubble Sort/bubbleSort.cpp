#include <iostream>

// we actually study bubble sort while back
// its really easy
// Bubble Sort repeatedly steps through the list, compares adjacent elements, 
// and swaps them if they are in the wrong order. This process is repeated until the list is sorted.

// btw this is called adaptive optimization.
// because we didn't use the function of swap 
// we created manually

void sort(int arr[], int n) {

  int temp;

  for(int i = 0; i < n - 1; i++) {
    bool swapped = false;
      for(int j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
          swapped = true;
        }
      }
    if(!swapped) {
      break;
    }
  }

  std::cout << "Sorted Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " "; 
  } 

}

int main() {

  int arr[] = {4, 3, 6, 2, 1, 5, 7, 9, 10, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, n);

  return 0;
}