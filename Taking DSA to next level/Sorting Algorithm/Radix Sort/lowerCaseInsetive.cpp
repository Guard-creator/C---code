#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

// Converts a string to lowercase (used for case-insensitive comparisons)
std::string tolowerCase(const std::string &str) {
  std::string result = str;
  for(char& ch : result) {
    ch = tolower(ch);  // convert each character to lowercase
  }
  return result;
}

// Performs counting sort on the vector of pairs based on character at position `pos`
// It uses the second (lowercased) string in the pair for comparison
void countingSort(std::vector<std::pair<std::string, std::string>>& arr, int pos) {
  int n = arr.size();
  int range = 256;  // ASCII range

  std::vector<int> count(range, 0);

  // Count frequencies of characters at `pos`, using the lowercased version
  for(int i = 0 ; i < n; i++) {
    int ch = pos < arr[i].second.size() ? arr[i].second[pos] : 0;
    count[ch]++;
  }

  // Convert count to prefix sum array
  for(int i = 1; i < range; i++) {
    count[i] += count[i - 1]; 
  }

  std::vector<std::pair<std::string, std::string>> output(n);

  // Build output array in stable order (from right to left)
  for(int i = n - 1; i >= 0; i--) {
    int ch = pos < arr[i].second.size() ? arr[i].second[pos] : 0;
    output[count[ch] - 1] = arr[i];
    count[ch]--;
  }

  arr = output;
}

void radixSortCaseInsensitive(std::vector<std::string>& arr) {
  int maxlen = 0;

  // Find the longest string length
  for(const std::string& s : arr) {
    maxlen = std::max(maxlen, (int)s.length());
  }

  std::vector<std::pair<std::string, std::string>> data;

  // Pair each original string with its lowercase version
  // The lowercase version will be used for sorting comparisons
  for(const std::string &s : arr) {
    data.emplace_back(s, tolowerCase(s));
  }

  // Apply counting sort on each character position from right to left
  // This is how radix sort works – sort by least significant position first
  for(int pos = maxlen - 1; pos >= 0; pos--) {
    countingSort(data, pos);
  }

  // Extract the sorted original strings (not the lowercase ones)
  for(int i = 0; i < arr.size(); i++) {
    arr[i] = data[i].first;
  }
}

int main() {
  std::vector<std::string> arr = {
      "Apple", "banana", "Bat", "cat", "Car"
  };

  radixSortCaseInsensitive(arr);

  for (const std::string& word : arr) {
      std::cout << word << std::endl;
  }

  return 0;
}
