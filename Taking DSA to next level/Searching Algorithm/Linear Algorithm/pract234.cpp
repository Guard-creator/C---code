#include <iostream>

// search im 2d arrays 
// an more efficient is to use vector to be more flexible
// which i will done in other file

bool search2D(int matrix[][4], int row, int col, int target, int &foundRow, int &foundCol) {

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] == target) {
        foundRow = i;
        foundCol = j;
        return true;
      }
    }
  }

  return false;
}

int main() {

  int arr[3][4] = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
  };

  int target = 11;
  int row, col;

  if(search2D(arr, 3, 4, target, row, col)) {
    std::cout << target << " was found in row " << row + 1 << ", col " << col + 1 << '\n'; 
  } else {
    std::cout << target << "was not found in array.\n";
  }

  return 0;
} 