#include <iostream>

  // you can also pass double data types in function template at same time

  template <typename T, typename  U>
  // using auto, its check both side which data type is higher then 
  // give the output of what tYPE data is...
  auto min(T x, U y) {
    return (x > y) ? x : y; 
  }
 
int main() {

  std::cout << "Mininum Value: " << min(5, 6.5) << '\n';

  return 0;
}