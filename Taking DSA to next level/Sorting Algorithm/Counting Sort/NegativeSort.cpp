#include <iostream>
#include <algorithm>
#include <vector>

// in default counting sort we cant sort negative values 
// so we do here :')

void negativeSort(std::vector<int>& arr) {

  int n = arr.size();

  // first we find max and min 
  // max → to know the highest value
  // min → to shift all values into positive space
  // because values are negative, and index work with only positive index
  // like 0, 1, 2 not 0, -1, -2
  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());

  // this cover all the values from max to min
  // +1 for the min values (because negative)
  int range = max - min + 1;
  std::vector<int> count(range, 0);
  std::vector<int> output(n);

  /* here we count frequencies of element
     because array have negative element we do - min
     to change the order for array access 
  
    what we are tring to do is that creating positive index for
    negative values pretend.
    🔧 So we “shift” all values to make them positive.
    We do that by subtracting the minimum value from every element.
    This way:
    The smallest number becomes index 0
    All other numbers become positive indexes above 0.
    array = -2, -1, -2, -3, -1, 0
    so to get postive index so we - min to get the positive index
    count = 1, 2, 2, 1
    index = 0, 1, 2, 3
    array = -3, -2, -1, 0 

    it work because subtracting min just shifts the whole range of values to start at 0.
    The distance between numbers stays the same
    But the lowest number becomes 0
    You don’t change the relative order, just make them valid for array access.
  */
  for(int i = 0 ; i < n; i++) {
    count[arr[i] - min]++;
  }

  // Prefix sum is where we find actual positions in the sorted array.
  for(int i = 1; i < range; i++) {
    count[i] += count[i - 1]; 
  }

  // and make the output array and sorted
  // here we also did arr[i] - min for array access
  // same idea yk
  for(int i = n - 1; i >= 0; i--) {
    output[--count[arr[i] - min]] = arr[i];
  }

  // just put back everything again in array with completly sorted
  arr = output;

}

int main() {

  std::vector<int> arr = {-2, -1, -2, -3, -1, 0};

  negativeSort(arr);

  for(int a : arr) {
    std::cout << a << " ";
  }

  return 0;
}