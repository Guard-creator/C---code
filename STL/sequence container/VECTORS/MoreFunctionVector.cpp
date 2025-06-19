#include <iostream>
#include <vector>

int main() {

  std::vector<int> numbers = {7, 43, 53, 23, 78, 24, 54};
  std::vector<std::string> phonk;

  // add the element at the  end of vector
  numbers.push_back(56);
  phonk.push_back("Brazilain");
  
  // locate the element in the vector  
  // you can also do this like this numbers[0];
  // std::cout << numbers.at(0) << '\n';

  std::cout << '\n';

  // remove the last element
  numbers.pop_back();

  // numbers.size() used to 
  // get the length of vector

  for(int i = 0; i < numbers.size(); i++) {
    std::cout << i + 1 << ". " << numbers[i] << '\n';
  }

  std::cout << '\n';

  // used to clear all the 
  // element of the vector
  phonk.clear();

  for(int i = 0; i < phonk.size(); i++) {
    std::cout << i + 1 << ". " << phonk[i] << '\n';
  }

  return 0;
}