#include <iostream>
#include <vector>
#include <algorithm>

// This is not a sorting algorithm,
// but it's related to the idea of sorting using cycles.
// It is used to find the minimum number of swaps 
// required to sort an array.

// We start by pairing each element with its original index.
// For example, arr = {4, 1, 3, 2} becomes:
// valueIndex = [(4,0), (1,1), (3,2), (2,3)]

// Then we sort this list by the values, not by their indices:
// valueIndex = [(1,1), (2,3), (3,2), (4,0)]

// Now this tells us:
// - 1 should be at index 0 (originally from index 1)
// - 2 should be at index 1 (from index 3)
// - 3 should be at index 2 (from index 2, already correct)
// - 4 should be at index 3 (from index 0)

// We create a boolean `visited[]` array to keep track of
// whether an element has already been part of a swap cycle.

int minSwap(std::vector<int> &arr) {
    int n = arr.size();

    // Pair each value with its original index
    std::vector<std::pair<int, int>> valueIndex;
    for (int i = 0; i < n; i++) {
        valueIndex.push_back({arr[i], i});
    }

    // Sort the valueIndex by the values (first element of the pair)
    std::sort(valueIndex.begin(), valueIndex.end());

    // Track visited elements
    std::vector<bool> visited(n, false);
    int swap = 0;

    for (int i = 0; i < n; i++) {
        // Skip already visited or correctly placed elements
        if (visited[i] || valueIndex[i].second == i)
            continue;

        int cycle = 0;
        int j = i;

        // Traverse the cycle of misplacements
        while (!visited[j]) {
            visited[j] = true;

            // Jump to the index where the current value should go
            j = valueIndex[j].second;
            cycle++;
        }

        // A cycle of size `cycle` needs `cycle - 1` swaps
        if (cycle > 1) {
            swap += (cycle - 1);
        }
    }

    return swap;
}

int main() {
    std::vector<int> arr = {4, 1, 2, 3};

    std::cout << "Minimum swaps needed: " << minSwap(arr) << '\n';
    return 0;
}
