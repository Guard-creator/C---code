#include <iostream>

int fem(int n) {
  std::cout << "Calling fib(" << n << "). \n";
  if(n <= 1) return n;
  return fem(n - 1) + fem(n - 2);
}

int main() {

  std::cout << fem(4) << '\n';

  return 0;
}