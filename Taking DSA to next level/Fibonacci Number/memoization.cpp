#include <iostream>
#include <unordered_map>  // for memoization

std::unordered_map<int, int> memo; // this will store fib(n)

int fib(int n) {
    if (n <= 1) return n;

    // Check if already computed
    if (memo.count(n)) return memo[n];

    // If not, compute and store it
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Fibonacci number at index " << n << " is: " << fib(n) << '\n';

    return 0;
}

/*

You only solve each fib(n) once.
After that, it's stored in memory (inside memo map).
If you need it again, you just read from memory — super fast!

// for ex

To solve fib(100), the function needs to calculate:
fib(99) + fib(98)
To get fib(99), it needs fib(98) + fib(97)
To get fib(98), it needs fib(97) + fib(96)
And so on...
🔁 BUT — with memoization:
Instead of calculating fib(98) again inside fib(99) (which would waste time), it says:
“Wait, I already solved fib(98) earlier. It’s in the memo map. I’ll just use that.”

*/
