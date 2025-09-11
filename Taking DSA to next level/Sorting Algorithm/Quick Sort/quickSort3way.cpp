#include <iostream>

// 3 ways of sort
// if a arry has double element or more then that
// quick sort will be more slower and cause issue
// so we use 3 ways to sort it 
// < less then 
// > greater then
// == equal to (to skip the double ones) 

void quickSort3Way(int arr[], int low, int high) {
    // return if already check the left side 
    // check the right side
    if (low >= high) return;

    // lt → the boundary for less than pivot
    // gt → the boundary for greater than pivot
    // i → the current index

    int lt = low, i = low + 1, gt = high;
    int pivot = arr[low];

    while (i <= gt) {
        if (arr[i] < pivot) {
            // we did it++ cuz 
            // a element is found that is less then pivot means it should be at first
            // so we swap the element with currrent index
            // and move the index forward and it because it is less then pivot
            // and safely to move forward
            std::swap(arr[i], arr[lt]);
            lt++; i++;
        }
        else if (arr[i] > pivot) {
            // we didn't increament i here cause we dont know 
            // what is arr[gt] in array 
            // we swap the element that is greater then pivot 
            // and do gt-- so we will look at that later
            // and sort that gt that got swap with current index i.  
            std::swap(arr[i], arr[gt]);
            gt--;
        }
        else {
            // skip the element that is same to the next
            i++;
        }
    }

    quickSort3Way(arr, low, lt - 1); // go left 
    quickSort3Way(arr, gt + 1, high); // go right
}


int main() {

  int arr[] = {4, 3, 4, 2, 4, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort3Way(arr, 0, n - 1);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}