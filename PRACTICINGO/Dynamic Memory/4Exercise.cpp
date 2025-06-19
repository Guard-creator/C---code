#include <iostream>

int main() {

  int rows, columns;

  std::cout << "Rows??: ";
  std::cin >> rows;

  std::cout << "Columns??: ";
  std::cin >> columns;

  int ** matrix = new int*[rows];

  for(int i = 0; i < rows; i++) {
    matrix[i] = new int[columns];
  }

  std::cout << "Enter The Element of Matrix: \n";
  
  for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
          std::cout << "Element [" << i + 1 << "][" << j + 1 << "]: "; 
          std::cin >> matrix[i][j];
      }
  }

  std::cout << "Matrix: \n";


  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}