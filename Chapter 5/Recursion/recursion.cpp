#include <iostream>

// recursion is a method to do something again and again 
// like loops or when you want to iterate over something.

// unlike loops recursion use function to call itself
// until the base is true like down below.

// it's kinda useless in my opinion but i  think 
// it will help in data structure or alogrithm .

// bro also says when sorting array with different method 
// rescursion is gonna be more useful.

// careful when using it or it will cause stack overflow 
// when function keep calling itself again and again.

int factorial(int number);

int main() {

  std::cout << factorial(10);

  return 0;
}

int factorial(int number) {
  if(number > 1) {
    return number * factorial(number - 1);
  } else {
    return 1;
  }
}