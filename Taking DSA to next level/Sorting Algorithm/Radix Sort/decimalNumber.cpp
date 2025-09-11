#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Now let's spice things up
// We're going to sort floating-point (decimal) numbers using radix sort — including negative numbers!
// -> Multiply each float by a power of 10 (e.g., 100 for 2 decimal places) to turn it into an integer.
//    This way, 3.14 becomes 314 and -2.71 becomes -271.
// -> Apply radix sort like normal (but handle negatives separately since radix only works on non-negative).
// -> After sorting, divide all numbers by the same power of 10 (e.g., 100) to convert them back to float.
//    This gives us correctly sorted decimal numbers with up to 2 digits of precision.


void countingSort(std::vector<int> &arr, int exp) {

  int n = arr.size();

  std::vector<int> count(10);
  
  for(int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for(int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  std::vector<int> output(n);
 
  for(int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  arr = output;
 
}

void radixSort(std::vector<int> &arr) {

  int max = *max_element(arr.begin(), arr.end());

  for(int exp = 1; max / exp > 0; exp*=10) {
    countingSort(arr, exp);
  }

}

void radixSortFloats(std::vector<float> &arr, int precision) {

  std::vector<int> scaleArr;

  // This factor determines how many decimal places we want to preserve.
  // For example, if precision = 2, we multiply each number by 100
  // to keep the first two decimal digits.
  int factor = pow(10, precision);

  // Convert each float to an integer by multiplying with the factor.
  // Example: 3.14 → 314
  for (float num : arr) {
    scaleArr.push_back(round(num * factor));
  }

  std::vector<int> negative, positive;

  // Separate negative and positive numbers into different arrays.
  // Store negatives as positive temporarily for radix sort.
  for (int num : scaleArr) {
    if (num >= 0) {
      positive.push_back(num);
    } else {
      negative.push_back(-num);  // make them positive for now
    }
  }

  // Apply radix sort to both arrays (if not empty).
  if (!positive.empty()) radixSort(positive);
  if (!negative.empty()) radixSort(negative);

  // Reverse the sorted negative array and restore negative signs.
  std::reverse(negative.begin(), negative.end());
  for (int &num : negative) {
    num = -num;
  }

  // Merge both sorted parts back into scaleArr.
  scaleArr.clear();
  for (int num : negative) scaleArr.push_back(num);
  for (int num : positive) scaleArr.push_back(num);

  // Convert the sorted integers back to float by dividing with the factor.
  arr.clear();
  for (int num : scaleArr) {
    arr.push_back((float)num / factor);
  }
}


int main() {

    std::vector<float> arr = {3.14, -2.71, 0.5, -0.01, 10.01, 2.0};

    radixSortFloats(arr, 2);

    for (float num : arr) {
        std::cout << num << " ";
    }

    return 0;

}