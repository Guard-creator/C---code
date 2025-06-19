#include <iostream>

// we split the array in half 
// so both left and right side are searching 
// this is best approach when array is completly rotated..

int searchRotatedArray(int nums[], int size, int target) {

  int low = 0;
  int high = size - 1;
 
  while(low <= high) {

    int mid = low + (high - low) / 2;

    if(nums[mid] == target) return mid;

    if(nums[low] <= nums[mid]) {

      if(nums[low] <= target && nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }

    } else {

      if(nums[high] >= target && nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }

    }

  }

  return -1;

}

int main() {

  int nums[] = {4, 5, 6, 7, 0, 1, 2};
  int size = sizeof(nums) / sizeof(nums[0]);
  int target = 0;

  int result = searchRotatedArray(nums, size, target);

  if(result != -1) {
    std::cout << target << " was found in Rotated Array at index: " << result << '\n';
  } else {
    std::cout << target << " was not found.\n";
  }

  return 0;
}