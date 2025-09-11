#include <iostream>
#include <cmath>

// Quick Sort’s speed depends on picking a good pivot (a middle value).
// But sometimes it picks a very bad pivot (like the smallest number every time). Then this happens:
/*
arr = [1, 2, 3, 4, 5]

Pivot = 1
→ Left = []
→ Right = [2, 3, 4, 5]
Then pivot = 2
→ Left = []
→ Right = [3, 4, 5]

It keeps repeating...

That means:

Nothing on left

Everything on right

1 + 2 + 3 + 4... comparisons = O(n²) ❌ (slow)
*/
/*
In Randomized Quick Sort:
int pivot = random(low, high);
This helps A LOT — it makes bad pivot less likely.
But random is still just chance.
Imagine you flip a coin and get heads 10 times in a row. It's rare — but possible. Same with bad pivots.
So in very rare bad luck, it can still run slowly (O(n²)).
*/
// IntroSort is smart:
// It starts with Quick Sort
// It watches how deep the recursion is going
// If it sees that recursion is going too deep, it switches to another sorting method — called Heap Sort
// Heap Sort is always safe: O(n log n)

// this is used when array is small 
// so we dont waste time on recursion we just do insertion
void insertion(int arr[], int low, int high) {
    for(int i = 1; i < high; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// quickSort method same
// but it will happen when array is too big < 16
// and if the recursion takes too long like suppose 16 size 
// and have to 2 * log2(4) so 8 recursion have to happen 
// but insetead it picks element the smallest  
// and recursion goes like 10 or 20 or something
// it changes to heapSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void heapSort(int arr[], int low, int high) {
    // this is just Insertion method 
    // but fake one to implement heapSort
    insertion(arr, low, high);
}

void introSort(int arr[], int low, int high, int depthlimit) {
    // size of elements btw and high to low
    int size = high - low + 1;

    // if array is small like < 16
    // it do insertion no need to waste time 
    // on recursion or quickSort :*()
    if(size < 16) {
        insertion(arr, low, high);
        return;
    }

    // if recursion goes toooo deep
    // switch to safe method heapSort
    if(depthlimit == 0) {
        heapSort(arr, low, high);
        return;
    }

    // part of quickSort if array is too big do recursion to Sort it
    int pi = partition(arr, low, high);
    introSort(arr, low, pi - 1, depthlimit--); // go left 
    introSort(arr, pi + 1, high, depthlimit--); // go right
    // we do depthLimit-- 
    // because when recursion happen here we have to -1 in depthlimit
    // to tell that recursrion happen ones
    // if it goes below zero it switch to heap
}

void sort(int arr[], int n) {
    // depthlimit tell us the how much we are giving recursion
    // log2(n) tell us how many recursion gonna happen
    // so we double it and tell it complete it in that recursion
    // like when we 4 hours to someone to do the job but 
    // we give extra another 4 hours to complete it in 8 hours
    int depthlimit = 2 * log2(n);
    introSort(arr, 0, n - 1, depthlimit);
}

int main() {

  int arr[] = {6, 2, 8, 5, 3, 9, 1, 4, 7, 10, 23, 15, 22, 12, 53, 5, 76};
  int n = sizeof(arr)/sizeof(arr[0]);
  sort(arr, n);

  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}