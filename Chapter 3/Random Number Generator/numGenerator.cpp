#include <iostream>
#include <ctime>

int main () {

  // how to generate random numbers 
  // these numbers ar pseudo random number they are not truly random numbers but close.

  srand(time(NULL));

  // we have to add one because when we find remindiner btw 0 to 5,
  // the number cant be 5 it either be 0 to 4 
  // its because the largest remainder you can get is 19 
  // the number its self not possible because it would mean
  // no remainder at all that why we add 1.
  // and that number can be generates

  //  int num1 = rand();

  int num = (rand() % 20) + 1;

  std::cout << num;

  return 0;
}