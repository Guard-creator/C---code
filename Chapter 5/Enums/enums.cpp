#include <iostream>

  // Enums (Enumeration) are user-defined because programmers create 
  // them to define meaningful sets of values.

  // An enum (enumeration) is a user-defined data type in C++ that 
  // consists of a set of named integer constants. It helps make code 
  // more readable and maintainable by allowing you to use meaningful 
  // names instead of raw numbers.

  // its like variables but for different condition 
  // like we have three variable with value that are integer 
  // that will reach that soon we should use Enums instead of
  // using each variable. or number 

  // Enums make the code look like it make sence.

  // great if you are having multiple options.

int main() {

  // this remained constant
  enum Days {Monday, Tuesday, Wednesday,Thurday, Friday, Saturday, Sunday};

  Days today = Thurday;

  // instead of a name you can also set number
  // like 0, 1, 2, 3, 4,.....
  switch(today) {
    case Monday: std::cout << "its Monday";
                break;
    case Tuesday: std::cout << "its Tuesday";
                break;
    case Wednesday: std::cout << "its Wednesday";
                break;
    case Thurday: std::cout << "its Thurday";
                break;
    case Friday: std::cout << "its Friday";
                break;
    case Saturday: std::cout << "its Saturday";
                break;
    case Sunday: std::cout << "its Sunday";
                break;
  }

  return 0;
}