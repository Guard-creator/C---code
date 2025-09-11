#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Now we do radix sort on strings.
// We sort each character from right to left (last to first character).
// Just like digit buckets (0–9), we use ASCII codes for characters ('a' = 97, etc.)

void countingSort(std::vector<std::string> &arr, int pos) {

    const int range = 256; // Full ASCII character range
    int n = arr.size();

    std::vector<int> count(range, 0);

    // Count frequency of each character at position `pos`
    // If a string is shorter than `pos`, we use ASCII 0 ('\0')
    // For example, if pos = 6 and the word is "cat" (length = 3),
    // there's no character at that position, so we treat it as '\0'
    for (int i = 0; i < n; i++) {
        char ch = pos < arr[i].size() ? arr[i][pos] : 0;
        count[(int)ch]++;
    }

    // Compute prefix sum to get actual positions
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    std::vector<std::string> output(n);

    // Build output array using the count array
    // We loop from right to left to make the sort stable
    for (int i = n - 1; i >= 0; i--) {
        char ch = pos < arr[i].size() ? arr[i][pos] : 0;
        output[count[(int)ch] - 1] = arr[i];
        count[(int)ch]--;
    }

    // Copy sorted result back to original array
    arr = output;
}

void radixSortStrings(std::vector<std::string> &arr) {

    // Find the maximum length among all strings
    // So we know how many positions we need to sort
    int maxlen = 0;
    for (const std::string &s : arr) {
        maxlen = std::max(maxlen, (int)s.length());
    }

    // Sort from last character to first
    // We go right to left because radix sort must process
    // least significant characters first to preserve order (stable sort)
    for (int pos = maxlen - 1; pos >= 0; pos--) {
        countingSort(arr, pos);
    }
}

int main() {

    std::vector<std::string> arr = {
        "apple", "bat", "banana", "car", "cat"
    };

    radixSortStrings(arr);

    for (const std::string& word : arr) {
        std::cout << word << std::endl;
    }

    return 0;
}
