#include <iostream>
#include <vector>
#include <queue>

// what is smallest number in 3rd index in sorted arr

int kthElement(std::vector<int> num, int k) {

  std::priority_queue<int> pq;

  for(int i = 0; i < num.size(); i++) {

    pq.push(num[i]);

    if(pq.size() > k) {
      pq.pop();
    }

  }

  return pq.top();
}

int main() {

  std::vector<int> num = {3, 4, 7, 9, 2, 5};
  int k = 3;

  std::cout << "3-th Smallest Element is " << kthElement(num, k);

  return 0;
}