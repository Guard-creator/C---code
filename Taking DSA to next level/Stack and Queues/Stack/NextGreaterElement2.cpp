#include <iostream>
#include <vector>
#include <stack>

// Problem: Next Greater Element II

// LeetCode 503 | Medium | Monotonic Stack

// You're given a circular array nums.
// For each element, you must find the next greater element — the first element to 
// its right when looping around the array once.
// If no such element exists, return -1.

// Key Difference from 496
// The logic is almost identical, but now the array is circular.
// This means:
// For each element, you might have to look past the end and continue from the start.
// But you must not loop forever — only consider one wrap-around.

// EXPLAINING THE SOLUTION
// Because the array is circular, we simulate going around it twice by 
// looping from i = 0 to 2 * n - 1.
// We use nums[i % n] to “wrap around” and access elements again after the end.
// We use a stack to store indices of elements whose next greater element we haven’t found yet.
// For each element:
// If the stack is empty → just push the current index.
// If not empty → compare the current element (num) with the element at the index 
// stored at the top of the stack (nums[st.top()]).
// If num is greater, it means num is the next greater element for that previous index.
// Set res[st.top()] = num and pop the stack.
// (Repeat this check until stack is empty or top is bigger.)
// Finally, if i < n, push the current index into the stack.
// (We only push the first n elements because the second half is just for searching.)
// At the end, res contains the next greater element for each position (or -1 if none exists).

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        std::stack<int> st;

        for(int i = 0; i < n * 2; i++) {
          int num = nums[i % n];
          while(!st.empty() && nums[st.top()] < num) {
            res[st.top()] = num;
            st.pop();
          }
          if(i < n) st.push(i);
        }

        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 2, 1};

    std::vector<int> result = s.nextGreaterElements(nums);

    std::cout << "Result: ";
    for (int x : result) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
