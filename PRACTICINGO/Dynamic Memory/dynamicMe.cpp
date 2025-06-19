#include <iostream>

int main() {

  int size;
  std::cout << "Enter the Size of Array: ";
  std::cin >> size;

  int * array = new int[size];

  std::cout << "Enter the Element: \n";

  for(int i = 0; i < size; i++) {
    std::cout << i + 1 << ". ";
    std::cin >> array[i];
  }

  for(int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }

  char choice;
  std::cout << "Resize The Array? (Y/N): ";
  std::cin >> choice;

  if(choice == 'y' || choice == 'Y') {
    
    int newSize;

    std::cout << "How much you wanna Resize: ";
    std::cin >> newSize;

    int * newArray = new int[newSize];

    int elementToCopy = (newSize > size) ? size : newSize;

    for(int i = 0; i < elementToCopy; i++) {
      newArray[i] = array[i];
    }

    if(newSize > size) {
      std::cout << "Enter " << newSize - size << " Additional Element: \n";
      for(int i = size; i < newSize; i++) {
        std::cout << i + 1 << ". ";
        std::cin >> newArray[i];
      }
    }

    delete[] array;

    array = newArray;

    for(int i = 0; i < newSize; i++) {
      std::cout << array[i] << " ";
    }

    delete[] array;
    array = nullptr;

  } else {
    delete[] array;
    array = nullptr;
  }

  return 0;
}