#include <iostream>
#include <map>
#include <vector>

int main() {

    std::vector<int> arr = {10, 20, 30, 40, 50, 60};
    std::map<int, int> map;

    // If the key is not found, map.find() returns map.end().
    // map.end() returns an iterator that does not point to any element in the map.

    for(int i = 0; i < arr.size(); i++) {
        if(map.find(arr[i]) == map.end()) {
          map[arr[i]] = i;
        }
    }

    for(auto pr : map) {
      std::cout << "Element: " << pr.first << " exist in the " << pr.second << " Index.\n"; 
    }

    return 0;
}