#include <iostream>
#include <vector>
#include <algorithm>

// Radix Sort doesn't support negative numbers... until now :)
// So we separate positive and negative numbers first
// Negative numbers aren't directly supported in Radix Sort, 
// so we turn negative numbers into positive (by using their absolute values) and sort them.
// After sorting both positive and converted-negative arrays,
// we reverse the sorted negative array (since it's supposed to be in descending order),
// and turn the values back to negative.
// Finally, we merge both sorted arrays back into the original array.

void countingSort(std::vector<int> &arr, int exp) {

  int n = arr.size();
  std::vector<int> count(10);
  std::vector<int> output(n);

  for(int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for(int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for(int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  arr = output;
}

void radixSort(std::vector<int> &arr) {

  int max = *max_element(arr.begin(), arr.end());

  for(int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(arr, exp);
  }

}

void radixSotingWithNegative(std::vector<int> &arr) {

  // Separate positive and negative numbers from the array
  std::vector<int> positive;
  std::vector<int> negative;

  // Push values into respective arrays
  for(int num : arr) {
    if(num >= 0) {
      positive.push_back(num);
    } else {
      negative.push_back(-num); // store absolute value
    }
  }

  // Sort both arrays if they’re not empty
  if(!positive.empty()) {
    radixSort(positive);
  } 
  if(!negative.empty()) {
    radixSort(negative);
  }

  // Reverse the sorted "negatives" because they were turned into positive,
  // so now we flip them to descending order and turn them back to negative values
  std::reverse(negative.begin(), negative.end());
  for(int &num : negative) {
    num = -num;
  }

  // Clear original array and combine negative + positive into it
  arr.clear();
  for(int num : negative) arr.push_back(num);
  for(int num : positive) arr.push_back(num);
}

int main () {

  std::vector<int> arr = {170, -45, 75, -90, 802, 24, -2, 66};

  radixSotingWithNegative(arr);

  for(int num : arr) {
    std::cout << num << " ";
  }

}
