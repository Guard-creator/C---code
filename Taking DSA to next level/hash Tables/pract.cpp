#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

  unordered_map<int, int> map;

  vector<int> num = {1, 1, 1};
  int k = 2;

        map[0] = 1;
        int total = 0, count = 0;

        for (int n : num) {
            total += n;

            if (map.find(total - k) != map.end()) {
                std::cout << map[total - k];
                                count += map[total - k];
            }

            map[total]++;
        }


        return 0;
}