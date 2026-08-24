#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxSubArrayLen(vector<int>& nums, int k) {

  int left = 0, right = 0;
  int sum = nums[0];
  int len = 0;

  while(right < nums.size()) {
    while(left <= right && sum > k) {
      sum -=nums[left];
      left++;
    }
    if(sum == k) {
      len = max(len, right - left + 1);
    }
    right++;
    if(right < nums.size()) sum += nums[right];
  }

  return len;

}


int main() {

  vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
  int k = 3;

  int res = maxSubArrayLen(nums, k);

  if(res == 3) {
    cout << res << " Correcto.\n";
  } else {
    cout << "Wrontoo.\n";
  }

  return 0;

}