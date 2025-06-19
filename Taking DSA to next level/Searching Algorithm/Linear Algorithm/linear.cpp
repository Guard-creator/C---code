#include <iostream>

// Linear Search is a method to find a value in a list/array by 
// checking each element one by one, from start to end.

// Start from the first element.
// Compare it with the target value.
// If it matches → return the index.
// If not → move to the next element.
// If the end is reached without a match → value not found.

int linearSearch(int arr[], int size, int target) {

  for(int i = 0 ; i < size; i++) {
    if(target == arr[i]) {
      return i;
    }
  }

  return -1;
}

int main() {

  int arr[] = {23, 43, 65, 87, 86, 12};
  int size = sizeof(arr) / sizeof(arr[0]);

  int target;
  std::cout << "Which value u looking for now: ";
  std::cin >> target;

  int index = linearSearch(arr, size, target);

  if(index  != -1) {
    std::cout << "Value is Found in Array at Index " << index << '\n';
  } else {
    std::cout << "Value is Not Found.\n";
  }

  return 0;
}