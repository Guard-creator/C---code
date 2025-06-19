#include <iostream>

// this is alogrithm technique called bubble sort 
// its used to sort a array 
// bubble sory alogrithm is work like when first value is greater then the next value its swapped
// the first value get placed in temp variable then second value take place of first value
// then second value get placed with the temp value we assigned 
// then we will keep doing this until all value gets sorted 
// this is called bubble sort
// its not very efficient other then alogrithm but its my first 

void sort(int array[], int size);

int main() {

  int myNumbers[] = {8, 9, 4, 6, 7, 10, 2, 3, 1, 5};
  int size = sizeof(myNumbers)/sizeof(int);

  sort(myNumbers, size);

  for(int element : myNumbers) {
    std::cout << element << " ";
  }

  return 0;
}

void sort(int array[], int size) {

  int temp;

  // the outer loop will loop 8 times 
  // because the size - 1 is equal to 9 but when i get 9 
  // the condition 9 < 9 is not true so it will only runs 8 times.

  for(int i = 0; i < size - 1; i++) {
    
    for(int j = 0; j < size - i - 1; j++) {
      if(array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }

  }

}