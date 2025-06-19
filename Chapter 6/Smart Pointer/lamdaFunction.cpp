#include <iostream>
#include <memory>

// This line creates a std::shared_ptr named ptr that manages a dynamically 
// allocated array of 10 integers. It also specifies a custom deleter 
// (the lambda function) to ensure the array is properly deleted using delete[].

int main() {

  // In C++, when you create an object, you use parentheses to pass arguments to its constructor.

  // shared_ptr doesn't work with arrays

  // this is a object std::shared_ptr
  // a object have a construct that why after 
  // ptr we put brackets
  // shared_ptr is smart pointer but standard libaray prvided as a class
  // of shared_ptr that why we are passing two arugments to the constructor
  // in Brackets ...
  // one is a pointer to the array "new int[10]"
  // and the custom deleter where we use lamda function "[](int *p) {delete[] p;}"
  // A lambda function is just a small, unnamed function that you can define 
  // right where you need it. It’s like a "mini-function" that you can create 
  // on the spot without giving it a name.
  // in lamda function
  // [] is a capture clause to get any external variable (if need) in this case its empty [].
  // (int *p) here we pass a argument for lamda function where it manages "new int[10]".
  // lamda function work as a custom deleter since it doesn't work with array.
  // By passing the lambda function as the second argument, you’re telling the std::shared_ptr:
  // "When you’re done managing this array, use this lambda function to clean it up."

  std::shared_ptr<int[]> ptr(new int[10], [](int *p) {delete[] p;});

  for(int i = 0; i < 10; i++) {
    ptr[i] = (i + 1) * 3;
  }

  for(int i = 0; i < 10; i++) {
    std::cout << ptr[i] << " ";
  }

  // since using lamda function memory get's free
  // using arrays
  return 0;
}