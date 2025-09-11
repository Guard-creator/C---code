#include <iostream>
#include <vector>

// ✅ LeetCode 493 – Reverse Pairs
// A reverse pair is defined as:
// A pair of indices (i, j) such that:
// - i < j
// - nums[i] > 2 * nums[j]
//
// For example:
// Input:  [1, 3, 2, 3, 1]
// Index:   0  1  2  3  4
//
// Reverse pairs:
// (1, 4) → 3 > 2 * 1 → ✅
// (3, 4) → 3 > 2 * 1 → ✅
// Output: 2
//

// 🚀 Why not use brute force?
// A naive O(n^2) approach checks every pair:
//   for (int i = 0; i < n; ++i)
//     for (int j = i + 1; j < n; ++j)
//       if (nums[i] > 2 * nums[j]) count++;
// But this is too slow for large arrays (e.g. size 10^5).

// Optimized approach: Modified Merge Sort
// - Split the array into halves until size == 1
// - Count reverse pairs while merging the halves
// - Merge the halves back in sorted order
// This gives O(n log n) performance

int mergeSort(std::vector<int> &nums, int left, int mid, int right) {

    int count = 0;
    int j = mid + 1;

    // j starts from the beginning of the right half

    // Loop through every element in the left half
    for (int i = left; i <= mid; ++i) {

        // For current i (left side), move j (right side) as long as:
        // nums[i] > 2 * nums[j]
        // This checks if a reverse pair exists

        // Why we use (long long)?
        // To prevent overflow when multiplying large numbers like 10^9 * 2
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            // If condition true, move j forward to check next element
            // Because right half is sorted, all previous j are valid reverse pairs
            j++;
        }

        // When the loop ends, j points to the first number that fails the condition.
        // So total valid reverse pairs for current i are:
        // all j's from (mid+1) to (j - 1), which is exactly:
        // If j never moved → j == mid + 1 → count += 0 → no reverse pairs found
        count += j - (mid + 1);

    }

    // ✅ Standard merge process (merge two sorted halves)
    std::vector<int> temp;
    int i = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    // Copy sorted temp back into original array
    for (int k = left; k <= right; ++k) {
        nums[k] = temp[k - left];
    }

    return count;
}

// 📦 Recursive merge function to divide and conquer
int merge(std::vector<int> &nums, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    int count = 0;

    count += merge(nums, left, mid);              // Count in left half
    count += merge(nums, mid + 1, right);         // Count in right half
    count += mergeSort(nums, left, mid, right);   // Count across halves

    return count;
}

// 🔁 Main function to be called
int reversePairs(std::vector<int> &nums) {
    return merge(nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums = {1, 3, 2, 3, 1};
    std::cout << reversePairs(nums) << std::endl;  // Output: 2
    return 0;
}
