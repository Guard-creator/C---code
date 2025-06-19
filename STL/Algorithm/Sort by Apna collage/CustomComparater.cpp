#include <iostream>
#include <algorithm>
#include <vector>

// this is custom parameter for pair to sort second element

// if first and second condition, p1.second is 1 and p2.second is 1 means same
// then it will compare the p1.first and p2.first values
bool comparater(std::pair<int, int> p1, std::pair<int, int> p2) {
  if(p1.second < p2.second) return true;
  if(p1.second > p2.second) return false;

  if(p1.first < p2.first) return true;
  else return false;
}

// this just only compares valuu of second ones.
bool comparater1(std::pair<int, int> p1, std::pair<int, int> p2) {
  if(p1.second < p2.second) return true;
  return false;
};

int main() {

  std::cout << "===================================\n";

  std::vector<std::pair<int, int>> vecPair1 = {{3, 1}, {1, 1}, {9, 7},  {4, 9}};

  sort(vecPair1.begin(), vecPair1.end(), comparater);

  for(auto pr : vecPair1) {
    std::cout << pr.first << "|" << pr.second << '\n';
  }

  std::cout << "===================================\n";

  std::vector<std::pair<int, int>> vecPair2 = {{4, 2}, {3, 5}, {7, 7},  {2, 1}};

  sort(vecPair2.begin(), vecPair2.end(), comparater1);

  for(auto pr : vecPair2) {
    std::cout << pr.first << "|" << pr.second << '\n';
  }

    std::cout << "===================================\n";

  return 0;
}
