#include <iostream>

  // function Template are used when we need a function with different data types.
  // its can be used to generates as many overload function Each using different data types
  // like Cookie Cutter ..........

  // for suppose i want to sum number with different dataTypes are passing 
  // like char int double... well here how you can do this.......

  template <typename T>
  T max(T a, T b) {
    return (a > b) ? a : b;
  }

int main() {

  std::cout << max('5', '6');

  return 0;
}
