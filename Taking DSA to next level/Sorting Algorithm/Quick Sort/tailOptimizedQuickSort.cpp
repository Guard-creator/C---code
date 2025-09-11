#include <iostream>

// if for suppose array is milion or something 
// it gonna get stack overflow because a lot of recursion is happening
// in quicksort (we are talking about normal quick sort);

// because of that we check before recursion which side is small
// if it right side solve that one or the other one

int partition(int arr[], int low, int high) {

  int pivot = arr[high];
  int i = low - 1;
  
  for(int j = low; j < high; j++) {
    if(arr[j] < pivot) {
      i++;
      std::swap(arr[j], arr[i]);
    } 
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {

  while(low < high) {

    int pi = partition(arr, low, high);

    // after the partition function
    // the pivot elemnt will be aat right position i may be right or left
    // so we check if it right or left 
    // pi - low < high - pi if high and low are same and pi is like 3 or something
    // means 3 < 1 if high is 4 and low is 0
    // it means that we will handle right side because left side is big
    
    if(pi - low < high - pi) {
      quickSort(arr, low, pi - 1); // this will handle left if already sorted then move 
      low = pi + 1; // if left was handled, move to right
    } else {
      quickSort(arr, pi + 1, high); // this handle right side if already sorted then move
      high = pi - 1; // if right was handled, move to left
    }

  }

}

int main() {

  int arr[] = {5, 2, 3, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}