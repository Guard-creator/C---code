#include <iostream>

// same here
// no rocket science 
// we here to find min value

int findLowest(int arr[], int size) {

  int lowestVal = arr[0];

  for(int i = 0; i < size; i++) {
    if(arr[i] < lowestVal) {
      lowestVal = arr[i];;
    }
  } 

  return lowestVal;
}

int main() {

  int arr[] = {34, 2, 54, 621, 657, 45, 3, 23, 57};
  int size = sizeof(arr) / sizeof(0);

  std::cout << "The lowest Value in the Array: " << findLowest(arr, size) << '\n';

  return 0;
}