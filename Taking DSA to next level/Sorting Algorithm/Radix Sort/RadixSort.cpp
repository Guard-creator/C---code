#include <iostream>
#include <vector>
#include <algorithm>

// Radix Sort sorts numbers digit by digit, from right to left (units, tens, hundreds, etc.),
// and uses a stable sort (like Counting Sort) on each digit.

void countingSort(std::vector<int> &arr, int n, int exp) {

    // We make the count array size 10 only (for digits 0 to 9),
    // because when we're sorting by a single digit, we only care about 0–9,
    // not the full range of numbers.
    std::vector<int> count(10);
    std::vector<int> output(n);

    // Count how many times each digit appears at the current place (unit/tens/hundreds)
    // Example: to get the middle digit of 802, we do:
    // (802 / 10) % 10 = 80 % 10 = 0 → that's the tens digit
    for(int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Do prefix sum on count[] so we know actual positions in output array
    // This tells us: where should each digit's group start in the sorted output
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }


    // Build the output array from right to left to make the sort stable (backwards)
    // Stable = if two digits are the same, their original order stays the same in output
    // First, we find the digit using: (arr[i] / exp) % 10 → this gives us the current digit
    // Then we use count[digit] to find where that number should go in the output array
    // We subtract 1 because arrays start at index 0
    // Place the entire value (not just the digit), based on that digit's position
    // Then do count[digit]-- so if the same digit appears again, it goes to the next slot
    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;

}

void radixSort(std::vector<int> &arr) {

    // first we get the max element of array
    // because we need to know how many unit to sort
    // for example if 802 we gonna go to 100 unit
    int max = *max_element(arr.begin(), arr.end());
    int n = arr.size();

    // this give each unit to know which digit to sort
    // for example the loop is gonna start at 1
    // so its mean we gonna sort the last digit 
    // if 10 means middle and if 100 then its gonna sort first digit 
    // based on 802 digit number
    for(int exp = 1; max / exp > 0; exp*=10) {
        countingSort(arr, n, exp);
    }

}

int main() {

    std::vector<int> arr = {170, 2, 24, 45, 66, 75, 802, 90};

    radixSort(arr);

    for(int a : arr) {
        std::cout << a << " ";
    }

    return 0;
}
