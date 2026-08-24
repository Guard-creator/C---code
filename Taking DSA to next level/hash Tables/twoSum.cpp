#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // using hashmap
        
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {

            int num = nums[i];
            if(map.find(target - num) != map.end()) {
                return {i, map[target - num]};
            }
            map[num] = i;

        }

        return {};
    }
};

int main() {

  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  Solution s;
  vector<int> res = s.twoSum(nums, target);

  for(int a : res) {
    std::cout << a << " ";
  }

}