#include <iostream>

int main() {

  // here a variable x have a value of 50
  // px1 is a pointer pointing to that x value
  // then px2 is now pointing to a pointer that's pointing a pointer to a x value  
  // and so on with  px3

  int x = 50;
  int * pX1 = &x;
  int ** pX2 = &pX1;
  int *** pX3 = &pX2;

  std::cout << ***pX3 << '\n';

  std::cout << '\n';

  // Pointer in Array

  // Remember when you declare a array 
  // its decays means its automatically 
  // convert to a pointer pointing to first 
  // element of array...

  int array[] = {5, 6, 7, 8, 9, 4, 3};
  // here array is now pointing to &array[0]
  // to its first element
  int size = sizeof(array)/sizeof(array[0]);

  int * pArray = array;

  std::cout << *array << '\n';

   for(int i = 0; i < size; i++) {
    std::cout << i + 1 << ". " << *pArray << '\n'; 
    pArray++;
   } 

  //Decay does not happen in two cases:
  // 1. When using the sizeof operator: sizeof(array) gives the size of the entire array, not the pointer.
  // 2. When using the & operator: &array gives the address of the entire array, not the first element.

  return 0;
}