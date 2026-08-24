#include <bits/stdc++.h>

    // Daily Temperatures – LeetCode 739:
    // Given an array 'temperatures', return an array 'res' where res[i] is the number
    // of days you have to wait after day i to get a warmer temperature.
    // If there is no future day, res[i] = 0.

  /*  Approach: Monotonic Decreasing Stack:
      Use a stack to store indices of days whose warmer temperature is not found yet.
      As we iterate, if the current temperature is greater than the temperature
      at the top index of the stack, we've found the next warmer day for that index.
      Update the result for that index with the difference (i - top).
      Continue until stack is empty or current temperature is not warmer.
      Push current index into the stack.
      Remaining indices in the stack will have result = 0 (already default).
  */

    // btw i solve this on first try using same approach

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {

      int n = temperatures.size();
      std::vector<int> result(n, 0);
      std::stack<int> st;

      for(int i = 0; i < n; i++) {
        while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
          // i - st.top will get us the days when the temperature get's 
          // higher when temperature is temperatures[st.top()]
          result[st.top()] = i - st.top();
          st.pop();
        }
        st.push(i);
      }

      return result;

    }
};

int main() {
    Solution sol;
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> result = sol.dailyTemperatures(temperatures);

    std::cout << "Result: ";
    for (int days : result) std::cout << days << " ";
    std::cout << std::endl;

    return 0;
}
