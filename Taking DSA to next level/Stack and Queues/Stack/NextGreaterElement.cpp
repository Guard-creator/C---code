#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

// 496. Next Greater Element I
// Problem (plain)
// You’re given two arrays:
// nums1 — a subset of nums2 (every value in nums1 appears somewhere in nums2).
// nums2 — a larger array (usually given with distinct values in the official problem).
// For each element x in nums1, find the first greater element to the right of x in nums2.
// If there is no greater element to its right, answer -1.
// Output an array of answers in the same order as nums1.

// We use monotonic stack to get the greater element 
// A monotonic stack is a stack that keeps its elements sorted in one direction — 
// either always increasing or always decreasing — as we process a sequence.
// Monotonic Increasing Stack: top is smallest
// Monotonic Decreasing Stack: top is largest
// In this problem, we want the next greater element to the right → so we use a monotonic decreasing stack.
// That means:
// The stack always holds elements in descending order from bottom → top.
// Whenever a new number is bigger than the top, it’s the next greater for all smaller elements on top.

// Explanation of Problem
// Since nums1 is a subset of nums2, we know the next greater elements must 
// be found inside nums2.
// We loop through nums2 while maintaining a monotonic decreasing stack. 
// Whenever we see a number greater than the stack’s top, that number is 
// the next greater element for the top, so we record it in an unordered_map and pop it.
// After building this map, we iterate over nums1 and fetch their next 
// greater values from the map, using -1 if not found.

// Why stack
// The stack remembers elements that are still waiting for a greater element.
// Think of the stack as a waiting room:
// Each time we see a new number in nums2, we check if it's greater than the element on 
// top of the stack.
// If yes → we found the next greater element for that waiting element → record it 
// and remove it from the stack.
// If no → the current number goes into the waiting room too (stack).
// This allows us to process everything in one single pass — O(n) time.

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        std::stack<int> st;
        std::unordered_map<int, int> ng;

        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                ng[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        std::vector<int> res;
        for(int num : nums1) {
            res.push_back(ng.count(num) ? ng[num] : -1);
        }

        return res;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {2, 4};
    std::vector<int> nums2 = {1, 2, 3, 4};

    std::vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    

    std::cout << "Result: ";
    for (int val : ans) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
