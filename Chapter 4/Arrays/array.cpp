#include <iostream>

int main() {

  // arrays i have studied array in javascripts they are same but different synatax
  
  int array1[9] = {123, 12123, 43, 453, 5634, 4353,  3453, 435, 5335};

  // we have to tell which part of the array to display
  // otherwise it will show you where the data is located 
  // in number and text
  //std::cout << array1;

  std::cout << array1[0] << '\n';
  std::cout << array1[1] << '\n';
  std::cout << array1[2] << '\n';
  std::cout << array1[3] << '\n';
  std::cout << array1[4] << '\n';
  std::cout << array1[5] << '\n';
  std::cout << array1[6] << '\n';
  std::cout << array1[7] << '\n';
  std::cout << array1[8] << '\n';
  std::cout << array1[9] << '\n';

  // if we have to change to array data later
  // we have to tell how much data should be 
  // for suppose if we want 3 string
  // we type there in square brackets.

  double array2[3];

  array2[0] = 4.33;
  array2[1] = 764.35;
  array2[2] = 5.666;

  std::cout << '\n' << array2[0] << '\n';
  std::cout << array2[1] << '\n';
  std::cout << array2[2] << '\n';

  return 0;
}