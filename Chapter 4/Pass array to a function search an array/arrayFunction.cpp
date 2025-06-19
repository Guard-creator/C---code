#include <iostream>

double totalSum(double ramdomNumber[], double size);

int main() {

  // so when passing array to function you can pass the array
  // but you cant find the size of it in that function 
  // you have to pass the size of function
  // otherwise it show error.

  double ramdomNumber[] = {3312, 324, 543, 2322, 231, 3452};
  double size = sizeof(ramdomNumber)/sizeof(double); // we find the size of it
  double total = totalSum(ramdomNumber, size); // then pass it here

  std::cout << total;

  return 0;
}

// when we pass the array in a function
// it can no longer called array it becomes pointer (not learn yet)

double totalSum(double ramdomNumber[], double size) {

  double total = 0;

  for(int i = 0; i < size; i++) {
    total += ramdomNumber[i];
  }

  return total;

  /*
  double total = 0;

  for(int i = 0; i < sizeof(ramdomNumber)/sizeof(double); i++) {
    total += ramdomNumber[i];
  } 

  return total;
  */

}