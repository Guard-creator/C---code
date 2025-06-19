#include <iostream>

int findNum(int array[], int size, int myNum);

int main() {

  int numbers[] = {13, 23, 12, 45, 54, 63, 34, 56};
  int size = sizeof(numbers)/sizeof(numbers[0]);
  int index;
  int myNum;

  std::cout << "Enter the number you want to find in a array: \n";
  std::cin >> myNum;

  index = findNum(numbers, size, myNum);

  if(index != -1) {
    std::cout << "The number you're looking for is in index " << index << '\n';
  } else {
    std::cout << "The Number you're looking for is not in the array.\n";
  }


  return 0;
}

int findNum(int array[], int size, int myNum) {
  
  for(int i = 0; i < size; i++) {
    if(array[i] == myNum) {
      return i;
    }
  }
  
  return -1;

}