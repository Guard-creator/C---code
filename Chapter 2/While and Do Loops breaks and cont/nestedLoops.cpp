#include <iostream>

int main() {

  // A loop inside a loop is called nested loop
  // useful in many places.

  /*
    for(int i = 1; i <= 3; i++) {
      for(int j = 1; j <= 10; j++) {
        std::cout << j << ' ';
      }
      std::cout << '\n';
    }
  */

    /*
        int columns;
        int rows;
        char symbols;

        std::cout << "How many Columns do You Want: ";
        std::cin >> columns;
        
        std::cout << "How many rows do You Want: ";
        std::cin >> rows;

        std::cout << "Choose a symbol: ";
        std::cin >> symbols;

        for(int i = 1; i <= columns; i++) {

          for(int j = 1; j <= rows; j++) {
            std::cout << symbols;
          }

          std::cout << '\n';

        }
    */

   /*
    for(int i = 5; i >= 1; i--) {

        for(int j = 1; j <= i; j++) {
          std::cout << "#";
        }
          
        std::cout << '\n';
    }
  */

  int n;

  std::cout << "Enter How many rows do you want: ";
  std::cin >> n;
    // n = 5
  for(int i = 1; i <= n; i++) {

    for(int j = 1; j <= n - i; j++) {
      std::cout << " ";
    } 

    for(int j = 1; j <= 2 * i - 1; j++) {
      std::cout << "@";
    }
    
    std::cout << '\n';
  }

  return 0;
}