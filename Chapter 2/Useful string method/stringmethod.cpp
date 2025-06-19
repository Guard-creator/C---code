#include <iostream>
#include <cmath>

int main() {

  // the useful string method that are will be helpful in future
  // this method are also used in input when we create email or password or something.

  std::string name;

  std::cout << "Enter your Name: ";
  std::getline(std::cin, name);

  // the length function is used to see how many character string have.

  /*
    if(name.length() > 14) {
      std::cout << "name cant be more then 14 character";
    } else {
      std::cout << "Hello " << name;
    }
  */

  // when empty is used it will be true or false to check that the user input the name or not.
  // if not the statement is true and name is empty,
  // if yes the statement is false means the name is already input.

  /*
    if(name.empty()) {
      std::cout << "you Didn't enter you name.";
    } else {
      std::cout << "Hello " << name;
    }
  */

 // it just claer the the variable, that the name is input in.

  /*
    name.clear();;
    std::cout << "Hello " << name;
  */

 // append function add the string in the end you give to append
 // if you like input a username or something append will add a 
 // string in the end that we give to append.
 // kinda like how you make good to use.

  /*
    name.append("@gmail.com");
    std::cout << "Hello " << name;
  */

 // this used to locate a character when you put at function on a variable 
 // and see which character you want to display like if we want first character 
 // i put in at function 0.
 // kinda useful i guess.

  /*
    std::cout << name << '\n';
    std::cout << name.at(4) << '\n';
  */

  // used ti insert a string or character in which string characters you want to input
  // just simply put the number where you to put and the string to what to put.

  /*
    std::cout << name.insert(0, "Death");
  */

  // used to find specific character the programmer want 
  // and it will give you the locations in number.

  /*
    std::cout << name.find("a");
  */

  // used to erase a portion of string.

  /*
    std::cout << name.erase(0, 6);
  */

  return 0;
}