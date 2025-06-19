#include <iostream>
#include <deque>
#include <vector>

// in another separete file this is well explain this is just a algorithm
// window sliding alogrithm

std::vector<int> windowSliding(std::vector<int>& nums, int k) {

  std::deque<int> dq;
  std::vector<int> result;

  for(int i = 0; i < nums.size(); i++) {

    // maintain window boundaries
    if(!dq.empty() && dq.front() == i - k) dq.pop_front();

    // check which value is max
    while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

    // add in dq max value index
    dq.push_back(i);

    // add in final result
    if(i >= k - 1) result.push_back(nums[dq.front()]);
 
  }

  return result;

}

int main() {

  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  
  std::vector<int> result = windowSliding(nums, k);

  for(int element : result) {
    std::cout << element << " ";
  }

  return 0;
}