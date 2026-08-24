#include <iostream>
#include <vector>
using namespace std;

// LeetCode 933 – Number of Recent Calls
// Problem Idea:
// You have a system that receives ping requests at certain times (in milliseconds).
// You need to count how many requests were received within the last 3000 milliseconds 
// (3 seconds) every time a new ping happens.

// You’re building a small system that counts how many times someone has “pinged” 
// (called) your server in the last 3000 milliseconds (3 seconds).

// Solution Explain
// vector<int> records;
// int start;
// Records Save the Previous Pings
// start marks the index of the first valid (recent) ping in the record.
// So instead of actually deleting old pings,
// we just move the start pointer forward — that’s way faster.
// We go through Record[start] 
// and check that if (t - 3000) that record lies in the the 3000 Second Range
// if it doesn't we increment start++ so Forgetting the old Ping
// and Finally
// record.size() = total number of pings so far.
// start = number of pings that were removed (too old).
// So record.size() - start = number of recent pings in the last 3000ms.

// We can Also Use Queue for this 

class RecentCounter {
  vector<int> records;
  int start;
public:
    RecentCounter() : start(0) {}
    
    int ping(int t) {
      records.push_back(t);
      while(records[start] < t - 3000) {
        start++;
      }
      return records.size() - start;
    }
};

int main() {

  RecentCounter pr;

  std::cout << "Ping: 1, Count: " << pr.ping(1) << '\n';
  std::cout << "Ping: 100, Count: " << pr.ping(100) << '\n';
  std::cout << "Ping: 3001, Count: " << pr.ping(3001) << '\n';
  std::cout << "Ping: 3002, Count: " << pr.ping(3002) << '\n';

  return 0;
}