#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 First Solution comes top my mind
int maxSubArrayLen(vector<int>& nums, int k) {

  unordered_map<int, int> map;

  int sum = 0;
  int len = 0;

  for(int i = 0; i < nums.size(); i++) {

    sum += nums[i];
    
    if(map.find(sum - k) != map.end()) {
      int temp = i - map[sum - k];
      if(temp > len) {
        len = temp;
      }
    }
    map[sum] = i;

  }

  return len;

}
*/

int maxSubArrayLen(vector<int>& nums, int k) {

  unordered_map<int, int> map;

  int sum = 0;
  int len = 0;

  for(int i = 0; i < nums.size(); i++) {

    sum += nums[i];
    
    if(sum == k) {
      len = max(len, i + 1);
    }

    if(map.find(sum - k) != map.end()) {
      int temp= i - map[sum - k];
      len = max(len, temp);
    }

    if(map.find(sum) == map.end()) {
      map[sum] = i;
    }

  }

  return len;

}


int main() {

  vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
  int k = 3;

  int res = maxSubArrayLen(nums, k);

  if(res == 3) {
    cout << res << " Correcto.\n";
  } else {
    cout << "Wrontoo.\n";
  }

  return 0;

}