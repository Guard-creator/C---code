#include <iostream>

using string = std::string;

int main() {

  string menu[5];
  int size = sizeof(menu)/sizeof(menu[0]);
  string temp;

  for(int i = 0; i < size; i++) {

    std::cout << "Enter the Food you like or Enter 'q' to quit #" << i + 1 << ": ";
    std::getline(std::cin, temp);

    if(temp == "q") {
      break;
    } else {
      menu[i] = temp;
    }

  }

  for(int i = 0; !menu[i].empty(); i++) {
    std::cout << menu[i] << '\n';
  }

  return 0;
}