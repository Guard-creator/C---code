#include <iostream>

// we are sorting in desending order but it's
// really simple just do the reverse after sort but 
// let's do it without using any #include vector and reverse function

void desendingSort(int arr[], int n) {

  // finding max for counting frequencies
  int max = arr[0];
  for(int i = 1; i < n; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }

  int count[max + 1] = {};

  for(int i = 0 ; i < n; i++) {
    count[arr[i]]++;
  }
  
  for(int i = 1 ; i <= max; i++) {
    count[i] += count[i - 1];
  }

  int output[n];
  for(int i = n - 1; i >= 0; i--) {
    output[--count[arr[i]]] = arr[i];
  }
  
  for(int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  // you can also use a function for reverse
  // but because of the challenge we did manually
  // we can also use swap function but again challenge
  int temp = 0;
  for(int i = 0; i < n / 2; i++) {
    temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
  }

}
 
int main() {

  int arr[] = {5, 2, 1, 3, 4, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  desendingSort(arr, n);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}