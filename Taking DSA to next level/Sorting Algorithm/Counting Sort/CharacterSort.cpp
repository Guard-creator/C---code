#include <iostream>
#include <vector>

// we can actually use countingSort to sort character
// Characters like 'a', 'b', 'c' are just integers under the hood — 
// their ASCII values.
// Counting Sort works on integers, so it naturally works for characters 
// too by using their ASCII codes as indexes.

// remember this only sort lowercase character
// to use for all cases you can use an normal default countingSort
// but in default one count will have more waste memory and junk values

//  ✅ default version is flexible but heavier.
//  ✅ The 26-count version is lighter but limited.
void countingSort(char arr[], int n) {

  // we dont find max here cuz
  // in ASCII the alphabet in integer are 97, 98, 99, 100

  std::vector<int> count(26, 0);
  for(int i = 0; i < n; i++) {
    count[arr[i] - 'a']++;
  }
  // we did - 'a' to get the alphabetic value like 0, 1, 2
  // for suppose arr[i] is a in ASCII is 97 so we 'a' which is 97 that 
  // index will be 0 so on the 'b'

  for(int i = 1; i <= 26; i++) {
    count[i] += count[i - 1];
  }

  std::vector<char> output(n);
  for(int i = n - 1; i >= 0; i--) {
    output[--count[arr[i] - 'a']] = arr[i];
  }

  for(int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

}

int main() {

  char arr[] = {'b', 'a', 'd', 'a', 'c'};
  int n = sizeof(arr) / sizeof(arr[0]);

  countingSort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " "; 
  }

  return 0;
}