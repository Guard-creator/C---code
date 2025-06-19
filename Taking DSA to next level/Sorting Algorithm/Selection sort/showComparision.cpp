#include <iostream>

// showing comparision 
// very nice for debugging or learning

void sort(int arr[], int n) {

  for(int i = 0; i < n - 1; i++) {
    
    int minIndex = i;

    for(int j = i + 1; j < n; j++) {

      std::cout << "Comparing: arr[" << j << "] = " << arr[j] <<
      ", arr[" << minIndex << "] = " << arr[minIndex] << '\n';

      if(arr[j] < arr[minIndex]) {
        minIndex = j;
        std::cout << "New Min at Index " << minIndex << ": " 
        << arr[minIndex] << '\n';
      }
    }

    if(minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }

    std::cout << "Pass: " << i + 1 << ": ";
    for(int k = 0; k < n; k++) {
      std::cout << arr[k] << " ";
    }
    std::cout << '\n';
 
  }

}

int main() {

  int arr[] = {4, 2, 1, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, n);

  std::cout << "Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  
  return 0;
}