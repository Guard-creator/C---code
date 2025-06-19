#include <iostream>
#include <algorithm>

// function but who use this bruh

int main() {

    int arr1[] = {34, 2, 54, 621, 657, 45, 3, 23, 57};
    int arr2[] = {32, 2312, 5, 33, 46, 78, 1332, 542, 432};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int maxVal = *std::max_element(arr1, arr1 + size1);
    int minVal = *std::min_element(arr2, arr2 + size2);

    std::cout << "Max in arr1 is " << maxVal << '\n';
    std::cout << "Min in arr2 is " << minVal << '\n';

  return 0;
}