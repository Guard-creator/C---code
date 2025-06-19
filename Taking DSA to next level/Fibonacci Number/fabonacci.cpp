#include <iostream>

// The two first Fibonacci numbers are 0 and 1, and the next Fibonacci number is always 
// the sum of the two previous numbers, so we get 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

int main() {

  int prev1 = 0;
  int prev2 = 1;

  std::cout << prev1 << " ";
  std::cout << prev2 << " ";
  
  int newfem;

  for(int i = 0; i < 10; i++) {
    newfem = prev1 + prev2;
    prev1 = prev2;
    prev2 = newfem;
    std::cout << newfem << " ";
  }

  return 0;
}