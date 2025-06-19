#include <iostream>

using string = std::string;

int findFood(string array[], int size, string searchFood);

int main() {

   string menu[] = {"Egg", "Bread", "SandWich", "Biryani", "Halwa poori"};
   int size = sizeof(menu)/sizeof(string);
   int index;
   string searchFood;

   std::cout << "Enter the food you want: ";
   std::getline(std::cin, searchFood);

   index = findFood(menu, size, searchFood);

   if(index != -1) {
    std::cout << "The food is in index " << index << '\n';
   } else {
    std::cout << "Food is not located\n";
   }

  return 0;
}

int findFood(string array[], int size, string searchFood) {

  for(int i = 0; i < size; i++) {
    if(array[i] == searchFood) {
      return i;
    }
  }

  return -1;

}