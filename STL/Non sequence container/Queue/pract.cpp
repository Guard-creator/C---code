#include <iostream>
#include <queue>

void reverseQueue(std::queue<int> &q) {

  if(q.empty()) return;

  int frontElement = q.front();
  q.pop();

  reverseQueue(q);

  q.push(frontElement);

}
 
int main() {

  std::queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  std::queue<int> temp = q;
  std::cout << "Before reverse: ";
  while(!temp.empty()) {
    std::cout << temp.front() << " ";
    temp.pop();
  }

  reverseQueue(q);

  std::cout << "After reverse: ";
  while(!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }

  return 0;
}