#include <iostream>
#include <vector>

// Merge sort
// merge sort keeps halving the array until one element remain then using recursion
// it merge them back with sorted order

// this function is used to sort the merging parts of array
/*
merge(0,0,1)   → [4, 8]
merge(0,1,2)   → [4, 5, 8]
merge(3,3,4)   → [2, 9]
merge(3,4,5)   → [1, 2, 9]
merge(0,2,5)   → [1, 2, 4, 5, 8, 9]
*/
void merge(std::vector<int>& arr, int start, int mid, int end) {
    // we put the sorted part in temp before actually 
    // putting them back to array
    std::vector<int> temp;
    // i is where we start from the left part of the beginning
    // and j is where we start from the right part of beginning that why we add + 1
    int i = start, j = mid + 1;

    // until i have element from left side keep comparing and also
    // until j have element till the end keep comparing 
    // if one of the condition fail it will ont gonna compare that side 
    // means if left side have some element but right side is already been compare 
    // it means that left side have been sorted already when it merging them back up
    // using recursion
    // if arr[i] is less then or equal to arr[j] then push the arr[i] in temp if not 
    // arr[j] is small push temp then
    // we also increment the i++ and j++ so we can move on to the next element to check  
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    // this is where leftover goes that have not been compare either left or right
    // if i <= mid means there are some element that have not been compare so we push them 
    // in temp because the element have already been compare we just have to push them
    // same idea with j <= end 
    // and we also i++ and j++ so if any values are left  
    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= end) temp.push_back(arr[j++]);

    // then after we we put back everything back in array 
    // that we merge
    // but we dont like fully changed the array we 
    // just the part of it that merge 
    // like this 
    // 8, 4, 5, 2, 9, 1 for suppose it's start = 0, mid = 0, end = 1;
    // then it will be 
    // [4, 8] 5, 2, 9, 1
    for(int k = 0; k < temp.size(); ++k)
        arr[start + k] = temp[k];
}


// this function is used to keep halfing until one element remain 
// after we reach to one element then we build back up and sort them by using 
// merge function 
// first we pass start to we where we are string and end to where it end
// then we add a if statement so it doesn't repeatly keep halfing the array 
// after one element remain we return it 
// mid is used to find the mid part or half of the array 
// after we found mid we got to parts now left and right 
// we first use recursion to left to also find the half and keep halfing until
// one element remain then sort back up
// same idea with the right side
/*

    mergeSort(0, 5)
    ├─ mergeSort(0, 2)
    │  ├─ mergeSort(0, 1)
    │  │  ├─ mergeSort(0, 0) → returns
    │  │  └─ mergeSort(1, 1) → returns
    │  │  └─ merge(0, 0, 1) ✅ → [4, 8]
    │  └─ mergeSort(2, 2) → returns
    │  └─ merge(0, 1, 2) ✅ → [4, 5, 8]
    |  That was just the left half of the original array!
    |  Now it goes to the right half of the original array:
    mergeSort(3, 5)
    ├─ mergeSort(3, 4)
    │  ├─ mergeSort(3, 3) → returns
    │  └─ mergeSort(4, 4) → returns
    │  └─ merge(3, 3, 4) ✅ → [2, 9]
    └─ mergeSort(5, 5) → returns
    └─ merge(3, 4, 5) ✅ → [1, 2, 9]

    Final merge:
    merge(0, 2, 5) ✅ → [1, 2, 4, 5, 8, 9]
*/
void mergeSort(std::vector<int>& arr, int start, int end) {
    // return when one element remain
    if(start >= end) return;

    int mid = (start + end) / 2; // to half the array 
    mergeSort(arr, start, mid); // go to left side 
    mergeSort(arr, mid + 1, end); // go to right side

    // first merging we always be start by more them 1 element 
    // then we sort them 
    merge(arr, start, mid, end);
}

int main() {
    std::vector<int> arr = {8, 4, 5, 2, 9, 1};
    mergeSort(arr, 0, arr.size() - 1);

    for(int x : arr) std::cout << x << " ";
    return 0;
}
