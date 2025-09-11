#include <iostream>
#include <vector>

// Inversion count tells us how "unsorted" or "messy" an array is.
// It helps us understand how far the array is from being sorted.

long long mergeSort(std::vector<int>& arr, int start, int mid, int end) {
    std::vector<int> temp;
    long long inversion = 0;

    int i = start, j = mid + 1;

    // We count inversions when arr[i] > arr[j] because:
    // Both halves (left and right) are sorted.
    // So if arr[i] > arr[j], then ALL elements from arr[i] to arr[mid]
    // are also greater than arr[j].
    // For example:
    // Left  = [3, 4, 5] (i)
    // Right = [1, 11, 22] (j)
    // When 3 > 1, it means:
    // (3,1), (4,1), (5,1) are all inversions → 3 inversions
    // So we add: inversion += (mid - i + 1)
    // and to count inversion we inv = mid - i + 1
    // mid - i is gonna give after the i values range so we get inversion
    // and we add +1 for correct inversion

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            inversion += mid - i + 1; // All remaining elements from left are greater than arr[j]
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }

    return inversion;
}

long long countInversion(std::vector<int>& arr, int start, int end) {
    if (start >= end) return 0;

    int mid = (start + end) / 2;

    // Each recursive call counts inversions in the left half, right half, and during merging.
    long long left = countInversion(arr, start, mid);
    long long right = countInversion(arr, mid + 1, end);
    long long merge = mergeSort(arr, start, mid, end);

    return left + right + merge;
}

int main() {
    std::vector<int> arr = {5, 2, 3, 1, 4, 6, 7};
    int n = arr.size();

    long long inversion = countInversion(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int a : arr) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    std::cout << "Inversion Count: " << inversion << '\n';

    return 0;
}
