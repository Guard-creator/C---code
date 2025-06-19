#include <iostream>
#include <queue>

int main() {

  std::priority_queue<int, std::vector<int>, std::greater<int>> q;

  int n;
  int size = 5;

  for(int i = 0; i < size; i++) {
    std::cout << "Element " << i + 1 << ": ";
    std::cin >> n;
    q.push(n);
  }

  while(!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }

};