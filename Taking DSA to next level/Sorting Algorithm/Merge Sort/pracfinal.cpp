#include <iostream>
#include <vector>

int mergeSort(std::vector<long long> &prefix, int left, int mid, int right, int lower, int upper) {

  int count = 0;
  int j = mid + 1, k = mid + 1;

  for(int i = left; i <= mid; i++) {
    while(k <= right && prefix[k] - prefix[i] < lower) k++;
    while(j <= right && prefix[j] - prefix[i] <= upper) j++;
    count += (j - k);
  }

  int l = left, r = mid + 1;
  std::vector<int> temp;

  while(l <= mid && r <= right) {
    if(prefix[l] <= prefix[r]) temp.push_back(prefix[l++]);
    else temp.push_back(prefix[r++]);
  }

  while(l <= mid) temp.push_back(prefix[l++]);
  while(r <= right) temp.push_back(prefix[r++]);

  for(int i = left; i <= right; i++) {
    prefix[i] = temp[i - left];
  }

  return count;

}

int merge(std::vector<long long> &prefix, int left, int right, int lower, int upper) {

  if(left >= right) return 0;

  int count = 0;
  int mid = (left + right) / 2;

  count += merge(prefix, left, mid, lower, upper);
  count += merge(prefix, mid + 1, right, lower, upper);
  count += mergeSort(prefix, left, mid, right, lower, upper);

  return count;

}

int countRangeSum(std::vector<int> &nums, int lower, int upper) {

  int n = nums.size();

  std::vector<long long> prefix(n + 1, 0);

  for(int i = 0; i < n; i++) {
    prefix[i + 1] = nums[i] + prefix[i];
  }

  return merge(prefix, 0, n, lower, upper);

}

int main() {

    std::vector<int> nums = {-2, 2, 3, 4, 1, 7};
    int lower = -2;
    int upper = 2;
    std::cout << countRangeSum(nums, lower, upper) << std::endl;

  return 0;
}