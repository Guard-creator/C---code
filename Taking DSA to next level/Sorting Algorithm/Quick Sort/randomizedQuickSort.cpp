#include <iostream>

// the worst case will 0(n2) happen when array is already sorted
// in quicksort when array is sorted and we try to use sorted again using quicksort
// we might get's error because it keep swaping does numbers that are already at the right place
// so in case 
// we do randomizedpartition swap to swap element this way if array is already sorted 
// it get unsoreted then do quicksort
// to prevent the worst case

int partition(int arr[], int low, int high) {

  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; j++) {
    if(arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

int randomizedPartition(int arr[], int low, int high) {
  int randomIndex = low + rand() % (high - low + 1);
  std::swap(arr[randomIndex], arr[high]);
  return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {

  if(low < high) {
    int pi = randomizedPartition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }

}

int main() {

  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}