#include <bits/stdc++.h>

// Problem 84: Largest Rectangle in Histogram
// Given an array heights representing the height of bars in a histogram, 
// find the area of the largest rectangle that can be formed inside the histogram.

// Example:
// Input: heights = [2,1,5,6,2,3]
// Output: 10

// Explanation:
// The largest rectangle is formed by heights [5,6] 
// (both next to each other) → height = 5, width = 2 → area = 5×2 = 10.

// You have bars like this:
//     █ █
//     █ █
// █   █ █   █
// █ █ █ █ █ █

// Each number in heights[] is the height of one vertical bar.
// Your task: Find the biggest rectangle you can draw inside the bars.

// APPROACH
// We use a **Monotonic Increasing Stack** approach.
// The stack stores indices of bars in **increasing order of heights**.
// That means: heights[st[0]] <= heights[st[1]] <= heights[st[2]] ...
// 
// For each bar:
// - If the current bar height is >= top of the stack, push its index.
//   (The increasing order continues.)
// 
// - If the current bar height is < top of the stack, that means
//   we’ve found the **right smaller element** for the bar on top of the stack.
//   So we stop and start calculating the area for that bar.
// 
// Steps to calculate the area:
// 1. Pop the top index → that bar’s height = heights[popped_index].
// 2. Now we find how wide this rectangle can stretch:
//    - Right boundary = current index (i), because that’s where the smaller bar appeared.
//    - Left boundary = st.top() (after popping).
//    - So width = i - st.top() - 1
//      (We subtract 1 because both boundaries themselves aren’t part of the rectangle).
// 3. If the stack becomes empty after popping,
//    that means the popped bar was the **smallest so far**, so:
//      width = i  (it extends all the way to index 0)
// 4. Compute area = height * width
// 5. Track the maximum area.
//
// Finally, after processing all bars, we push a dummy height 0
// (i == n case) to flush out any remaining bars in the stack.


class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st;
        int maxArea = 0;
        for(int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(height * width, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << s.largestRectangleArea(heights) << std::endl;
}
