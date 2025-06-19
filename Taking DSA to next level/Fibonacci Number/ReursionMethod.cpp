#include <iostream>

// a recursion method 
// 

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {

  // fn = (fn-1)  + (fn-2)
  // formula to find the fibonacci numbers
  // for example 
  // The sequence is 
  // 0, 1, 1, 2, 3, 5, 8, 13

  // so suppose we have to find f6 fibonacci(at index)
  // so n = 6 (index)
  // (n-1) + (n-2) = 5 + 4 
  // so before we sum it we got 5 and 4  
  // now 
  // at 5 index the fibonnaci number is 5
  // and at 4 the fibonnaci number is 3
  // so now sum 
  // 5 + 4 --- (5 + 3)
  // become 8
  // and that how it means 
  // (n - 1)  is the previous number
  // (n - 2) is the another prvious number before that 
  // and when we sum we get the other fibonacci number

  std::cout << "f6 " << fib(6) << '\n';
  std::cout << "f4 " << fib(4) << '\n';

  // fib(4)
  // ├── fib(3)
  // │   ├── fib(2)
  // │   │   ├── fib(1) → 1 ✅
  // │   │   └── fib(0) → 0 ✅
  // │   └── fib(1) → 1 ✅
  // └── fib(2)
  //    ├── fib(1) → 1 ✅
  //    └── fib(0) → 0 ✅

  // "The key is 0 and 1 are the base. Once we reach them, the actual Fibonacci pattern begins."
  // starts returning numbers back up the tree, like building a pyramid from the bottom.

  return 0;
}