#include <iostream>

using string = std::string;

string showBag(string bag[], int sizeofbag);

int main() {

  string bag[] = {"books", "pen", "lunchBox", "register", "files", "phone"};
  int sizeofbag = sizeof(bag)/sizeof(string);
  std::cout << showBag(bag, sizeofbag);

  return 0;
}

string showBag(string bag[], int sizeofbag) {

  string result;

  for(int i = 0; i < sizeofbag; i++) {
    result += bag[i] + " ";
  }

  return result;

}