#include <iostream>
#include <vector>

// another way to sort odd number but the previous in oddElement
// mine one is like less accurate 
// so i made this a little safer

void sortOddIndexedElements(int arr[], int n) {

  std::vector<int> vec;
  for(int i = 1; i < n; i+=2) {
    vec.push_back(arr[i]);
  }

  for(int i = 1; i < vec.size(); i++) {
    int key = vec[i];
    int j = i - 1;
    while(j >= 0 && vec[j] > key) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = key;
  }

  int index = 0;
  for(int i = 1; i < n; i+=2) {
    arr[i] = vec[index++];
  }

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}

int main() {
  
  int arr[] = {9, 1, 8, 2, 7, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  sortOddIndexedElements(arr, n);

  return 0;
}