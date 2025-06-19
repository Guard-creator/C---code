#include <iostream>
#include <vector>

// this is an non recursion method most fast and efficient.

int fib(int n) {

  if(n <= 1) return n;

  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2]; 
  }

  return dp[n];
}

int main() {

  int n;
  std::cout << "Enter n: ";
  std::cin >> n;

  std::cout << "The fibonacci number at index " << n << " is " << fib(n) << '\n';

  return 0;
}