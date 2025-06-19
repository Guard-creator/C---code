#include <iostream>

  // local variable that are declare inside a function can only be used in that function.
  // global variable that are declare outside of the function that can be used everywhere.

  // the variable are only accessible inside or outside depend on where are they created 
  // its called scope.

  //void useLocalVarb();

  // let use a global variable 

  std::string pizzaTaste = "Dammm It's Spicy.";

int main() {

  // its declare inside a function so its can only be access and seen here.

  std::string pizzaTaste = "Its really Good!!!.";
  std::cout << pizzaTaste << '\n';

  std::cout << ::pizzaTaste << '\n';

  return 0;
}

  // let try to used local variable outside 

      void useLocalVarb() {

          //std::cout << pizzaTaste;
          // we dont have to use scope resolution op because
          // we are inside a scope.
          std::cout << pizzaTaste << '\n';

      }

  // cause error as it seems.

  // if local and global varb name are same local varb will be access first 
  // if you have to use global varb we to use :: scope resolution operator.
