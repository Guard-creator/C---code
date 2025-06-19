#include <iostream>

using string = std::string;

int main() {

  // multidimentional array are 2d array or i my words i say nested array
  // i also study this in javascripts but this array synatax is different.
  
  string inventory[][3] = {{"sword", "Bow", "Gun"},
                           {"Egg", "Burger", "Pizza"},
                           {"keqing", "Neole", "Raiden Shogun"}};
  // i have to assign the value to tell how many array will be in there.

  // let find the size of arrays in there adn how many element in there
  // with rows as arrays and column as elemenet.

  int rows = sizeof(inventory)/sizeof(inventory[0]);
  int colunm = sizeof(inventory[0])/sizeof(inventory[0][0]);

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < colunm; j++) {
      std::cout << inventory[i][j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}