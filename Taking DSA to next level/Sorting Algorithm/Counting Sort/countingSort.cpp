#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // Step 1: Find max element
    // because in arr we dont know what value it is
    // if size is like 5 and value in the array is 10 or 20
    // it give garbage value or crash
    // because count vector make the array to the based on size 
    // so we can get how many times that value appear
    // arr[4, 7, 5, 4, 2] size = 5
    // max is 7             0, 1, 2, 3, 4, 5, 6, 7
    // count array will be [0, 0, 1, 0, 2, 1, 0, 1];
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    // Step 2: Initialize count array
    // We find the max value in the array so we know how big the count[] array needs to be.
    // we did max + 1 because if we did only max, it only create element of index 6
    // but to count frequency we need 7 index, that's why we do + 1
    vector<int> count(max + 1, 0);

    // Step 3: Store counts
    // we just count frequency of array that how many
    // times value appear so if arr is [3, 4, 2, 2]
    // count should look like this array = [0, 0, 2, 1, 1];
    //                             count =  0, 1, 2, 3, 4
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Modify count array to store positions
    // this is used to find the location of array
    // after frequency [0, 0, 2, 1, 1]
    // it gonna sum the the next element with 
    // previous one 
    // so at index, 3 is 1
    // we gonna add previous 2 at index 2
    // count[2] += count[i - 1];
    // 1 += 2 = 3
    // so at the end of prefix sum it should look like this [0, 0, 2, 3, 4];
    // so it means basically
    // in count[2] = 2 means there 2 values in array that are <= to 2
    // in count[3] = 3, there are 3 value in array that are <= to 3
    // in count[4] = 4, there are 4 values in array that are <= to 4
    // in orginal array
    // another way to thing this
    // if count[2] = 2 means in og array there are 2 values in array
    // that are <= to two // in og array[4, 2, 2, 3] // so yea there are at index 1 and 2
    // this is used to find the position of the element
    for(int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build output array (stable sort)
    // arr[i] is the one we gonna put it in right location 
    // so we take that and look at in count[arr[i]] 
    // once we get the location of that element we gonna 
    // --count[arr[i]] to put it in location
    // if arr[i] is 2
    // count[arr[i]] = 2 // means there are two element that are greater then 2 
    // which means to put in right location we do --count[arr[i]] to get 1..
    // so we can put it in correct position
    // but why in reverse 
    // because we dont want element like this [2{2}, 2{1}, 3, 4],
    // we  want it in [2{1}, 2{2}, 3, 4].
    vector<int> output(n);
    for(int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    // Step 6: Copy output to original array
    // now just put everything back in the array 
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}
