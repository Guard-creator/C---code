#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::vector<std::pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        std::sort(arr.begin(), arr.end());

        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int sum = arr[low].first + arr[high].first;
            if (sum == target) {
                return {arr[low].second, arr[high].second};
            } else if (sum < target) {
                low++;
            } else {
                high--;
            }
        }

        return {};

    }
};


int main() {

  std::vector<int> nums = {1, 3, 4, 6, 8, 10};
  int target = 14;

  Solution use;

  std::vector<int> result = use.twoSum(nums, target);

  std::cout << "[ ";
  for(int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << "]";

  return 0;
}