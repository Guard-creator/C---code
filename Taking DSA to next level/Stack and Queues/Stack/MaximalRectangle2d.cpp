#include <bits/stdc++.h>
using namespace std;

// LeetCode 85: Maximal Rectangle
// You are given a 2D binary matrix filled with '0's and '1's.
// You need to find the largest rectangle containing only '1's and return its area.

// Example: 
// Input:
// [
//   ['1','0','1','0','0'],
//   ['1','0','1','1','1'],
//   ['1','1','1','1','1'],
//   ['1','0','0','1','0']
// ]
// Output: 6
// The largest rectangle of 1s looks like
//       1 1 1
//       1 1 1
// with width of 3 and height of 2 (2 * 3) = 6 ans

// Relationship with Problem 84 ;)
//
// Problem 84: Given heights of bars, find largest rectangle in histogram.
// Problem 85: Same logic, but instead of a 1D histogram, you’re given multiple rows (2D).
//
// So we’ll treat every row as a histogram 
// At each row:
// If matrix[row][col] == '1', we add 1 to that column’s height.
// If it’s '0', we reset that column’s height to 0.
// Then, we call largestRectangleArea() (from problem #84) on this histogram.
// 
// Basically we are building bars of histogram with 2d array 
// then use the same function

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      stack<int> st;
      int maxArea = 0;
      for(int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];
        while(!st.empty() && currHeight < heights[st.top()]) {
          int height = heights[st.top()];
          st.pop();
          int width = st.empty() ? i : i - st.top() - 1;
          maxArea = max(height * width, maxArea);
        }
        st.push(i);
      }
      return maxArea;
    }
 
    int maximalRectangle(vector<vector<char>>& matrix) {

      int n = matrix[0].size();
      vector<int> heights(n, 0);
      int maxArea = 0;

      for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < n; j++) {
          if(matrix[i][j] == '1') heights[i] += 1;
          else heights[i] = 0;
        }
        int area = largestRectangleArea(heights);
        maxArea = max(area, maxArea);
      }

      return maxArea;
    }
};

int main() {

  vector<vector<char>> matrix = {
      {'1','0','1','0','0'},
      {'1','0','1','1','1'},
      {'1','1','1','1','1'},
      {'1','0','0','1','0'}
  };

  Solution sol;
  int area = sol.maximalRectangle(matrix);
  std::cout << "2d array max Area: " << area << '\n'; 

  return 0;
}
