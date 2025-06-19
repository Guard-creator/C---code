#include <iostream>
#include <vector>

// now empalce_back or front function works a little different in pairs

int main() {

    std::vector<std::pair<int, int>> p;

    // here then emplace doesn't need to pass a pair (with brackets)
    // you can just put the value and it will pass a pair for us
    p.emplace_back(5, 8);
    // while in push_back we have to pass as a pair
    // otherwise it wont work
    p.push_back({5, 9});

    for(int i = 0; i < p.size(); i++) {
      std::cout << "First value " 
      << p[i].first << " Second value " <<
      p[i].second << '\n';
    }

    // emplace_back here is great in this

  return 0;
}