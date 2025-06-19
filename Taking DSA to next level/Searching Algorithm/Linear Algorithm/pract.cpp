#include <iostream>
#include <unordered_map>

// this is much faster then the manual one 
/*

unordered_map to count frequencies (fast hash table)
Two simple loops
Efficient searching in O(n) time

*/

int findNonRepeatingNum(int arr[], int size) {

  std::unordered_map<int, int> map;

  for(int i = 0; i < size; i++) {
    map[arr[i]]++;
  }

  for(int i = 0; i < size; i++) {
    if(map[arr[i]] == 1) {
      return arr[i];
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