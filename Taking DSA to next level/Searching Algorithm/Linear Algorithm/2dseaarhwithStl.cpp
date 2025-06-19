#include <iostream>
#include <vector>

// quite flexible 
// but not useful in solving problems in leet

bool search2D(std::vector<std::vector<int>> vec, int target, int &row, int &col) {

  for(int i = 0; i < vec.size(); i++) {
    for(int j = 0; j < vec[i].size(); j++) {
      if(vec[i][j] == target) {
        row = i + 1;
        col = j + 1;
        return true;
      }
    }
  }

  return false;
}

int main() {

  std::vector<std::vector<int>> vec = 
  {{34, 3, 23},
   {67, 2, 78},
   {5, 43, 6}};

   int target = 78;
   int row, col;

   if(search2D(vec, target, row, col)) {
    std::cout << target << " was found in row: " << row << ", col: " << col << '\n';
   } else {
    std::cout << target << "was not found in array.\n";
   }
   

  return 0;
}