#include <iostream>
#include <set>

// 🔹 lower_bound(x)
// Returns an iterator pointing to the **first element that is >= x (greater than or equal to x).

// 🔹 upper_bound(x)
// Returns an iterator pointing to the **first element that is > x (strictly greater than x).

// If no such element exists (e.g. upper_bound(60)), then it returns s.end(), 
// which means "past the last element".

int main () {

  std::set<int> set1 = {1, 2, 3, 4, 5};
  std::set<int> set2 = {1, 2, 4, 5};

  std::cout << "Lower Bound: " << *set1.lower_bound(3) << '\n';
  std::cout << "Lower Bound: " << *set2.lower_bound(3) << '\n';

  std::cout << "Upper Bound: " << *set1.upper_bound(3) << '\n';
  std::cout << "Upper Bound: " << *set2.upper_bound(3) << '\n';

  // return last element
  std::cout << "Doesn't Exist: " << *set1.upper_bound(100) << '\n';

  return 0;
}