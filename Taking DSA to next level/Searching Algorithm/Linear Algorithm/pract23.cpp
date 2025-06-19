#include <iostream>

// manual one we have to make our own frequency map

int findNonRepeatingNum(int arr[], int size) {
  
  int unique[50]; // count those fresh unique number
  int count[50]; // count how many times a number appear
  int uniqueSize = 0; // count how many unique number we store in

  for(int i = 0; i < size; i++) {
    bool found = false;
      for(int j = 0; j < uniqueSize; j++) {
        if(unique[j] == arr[i]) {
          found = true;
          count[j]++;
          break;
        }
      }

    if(!found) {
      unique[uniqueSize] = arr[i];
      count[uniqueSize] = 1;
      uniqueSize++;
    }

  }

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < uniqueSize; j++) {
      if(unique[j] == arr[i] && count[j] == 1) {
        return arr[i];
      }
    }
  } 

  return -1;
}

int main() {

  int arr[] = {4, 5, 1, 2, 0, 4, 5, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  int result = findNonRepeatingNum(arr, size);

  if(result != -1) {
    std::cout << result << " was the first non repeating.\n";
  } else {
    std::cout << "No non-repeating element found.\n";
  }

  return 0;
}