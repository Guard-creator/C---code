#include <iostream>

int main() {

  int myNumbers[][3] = {{43, 76, 334},
                        {54, 312, 3424},
                        {65, 9754, 233}};

  int result = 0;

  int rows = sizeof(myNumbers)/sizeof(myNumbers[0]);
  int columns = sizeof(myNumbers[0])/sizeof(myNumbers[0][0]);

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      result += myNumbers[i][j];
    }
  }

  std::cout << result;
  
  return 0;
}