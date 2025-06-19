#include <iostream>
#include <queue>

struct Task {
  std::string name;
  int priority;

  Task(std::string n, int p) : name(n), priority(p) {};
};

struct CompareTask {
  bool operator() (const Task& a, const Task& b) {
    return a.priority > b.priority;
  }
};

int main() {

  std::priority_queue<Task, std::vector<Task>, CompareTask> q;

  q.push(Task("Gym", 1));
  q.push(Task("Eat", 2));
  q.push(Task("Sleep", 3));

  while(!q.empty()) {
    std::cout << "Task: " << q.top().name << " Priority: " << q.top().priority << ".\n";
    q.pop();
  }

  return 0;
}