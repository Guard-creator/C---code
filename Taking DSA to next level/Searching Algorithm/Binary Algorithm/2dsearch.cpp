#include <iostream>
#include <vector>

// here we are searching in 2d array 
// we have treat 2d array as 1d array

std::pair<int, int> searchMatrix(std::vector<std::vector<int>> matrix, int target) {

  // first we get the row and cols
  int row = matrix.size();
  int cols = matrix[0].size();

  // treating array as 1d here
  // low = 0 high = 12 - 1 = 11
  int low = 0;
  int high = (row * cols) - 1;

  while(low <= high) {

    // getting the mid the sitting row and cols
    // we divide with cols with mid to find its row 
    // we find remainder of mid % cols so we can get col..
    int mid = low + (high - low) / 2;
    int cRow = mid / cols, cCol = mid % cols;
    
    // getting midElement after wwe got row & cols
    int midElement = matrix[cRow][cCol];

    if(midElement == target) {
      return {cRow, cCol};
    } else if (midElement < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }

  }

  return {-1, -1};

}

int main() {

  std::vector<std::vector<int>> matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
  };

  int target = 3;

  std::pair<int, int> result = searchMatrix(matrix, target);
  
  if(result.first != -1 && result.second != -1) {
    std::cout << target << " was found at Row: " << result.first + 1 << ", Column: " << result.second + 1 << ".\n"; 
  } else {
    std::cout << "Target was not found in array.\n";
  }

}