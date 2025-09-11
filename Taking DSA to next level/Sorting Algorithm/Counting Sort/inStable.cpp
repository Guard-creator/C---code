#include <iostream>
#include <vector>

void inPlaceCountingSort(std::vector<int> & arr, int n) {

    // Find max value for count array size
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Build frequency count
    std::vector<int> count(max + 1);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    /* so here
      We’re using the count array to store how many times each value occurs in the original array.
      If count[i] > 0, that means the value i exists in the array.
      We enter the while (count[i] > 0) loop to write i back into the arr[] as many times as its frequency.
      Inside the loop:
      arr[index++] = i; puts the value into the array
      index++ moves us to the next empty spot
      count[i]-- reduces the frequency, since we’ve placed one copy of i
      This continues until all occurrences of i are placed in arr.
    */
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {

  std::vector<int> arr = {4, 2, 1, 3, 2};
  int n = arr.size();

  inPlaceCountingSort(arr, n);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

}