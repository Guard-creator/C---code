#include <iostream>
#include <queue>

int main() {

  std::queue<int> q;

  int size, n;

  std::cout << "Enter the size of Queue: ";
  std::cin >> size;

  std::cout << "Enter Element -> \n";
  for(int i = 0; i < size; i++) {
    std::cout << "Elmenet: " << i + 1 << '\n';
    std::cin >> n;
    q.push(n);
  }

  while(q.size() > 1) {
    int a = q.front(); q.pop();
    int b = q.front(); q.pop();
    int sum = a + b;

    std::cout << "Adding: " << a << " + " << b << " = " << sum << '\n';
    q.push(sum);
  }

  std::cout << "Result: " << q.front() << '\n';

  return 0;
};