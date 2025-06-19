#include <iostream>

using string = std::string;

void sort(string menu[], int size);

int main() {

  string menu[] = {"Burger", "Pizza", "Burger", "Egg", "Burger", "Pizza"}; 
  int size = sizeof(menu)/sizeof(menu[0]);

  sort(menu, size);

  for(string element : menu) {
    std::cout << element << " ";
  }

  return 0;
}

void sort(string array[], int size) {

  string temp;

  for(int i = 0; i < size - 1; i++) {

    for(int j = 0; j < size - i - 1; j++) {
      if(array[j] != "Burger") {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp; 
      }
    }

  }

}