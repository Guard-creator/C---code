#include <iostream>
#include <vector>
#include <climits>

// array is infinite 
// we dont know it's size so we have to guess it

int get(std::vector<int>& arr, int index) {
    if(index >= arr.size()) return INT_MAX; // we are running a simulation here
    return arr[index];
}

int searchInfiniteSortedArray(std::vector<int>& arr, int target) {

    // here we are trying to guess that element we are
    // looking for is truly lie btw those we are guessing

    int low = 0;
    int high = 1;

    while(get(arr, high) < target) {
        low = high;
        high *=2;
    }

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int midElm = get(arr, mid);

        if(midElm == target) {
            return mid;
        } else if (midElm < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

    } 

    return -1;
}

int main() {
    //  imagine this array is infinite
    std::vector<int> infiniteArray = {1, 3, 5, 7, 10, 13, 15, 18, 21, 25, 30, 35, 40};
    int target = 15;

    int index = searchInfiniteSortedArray(infiniteArray, target);

    if (index != -1) {
        std::cout << "Target " << target << " found at index: " << index << '\n';
    } else {
        std::cout << "Target not found in the array.\n";
    }

    return 0;
}
