#include <iostream>
#include <vector>

//typedef std::string string_t;
//typedef int number_t;
/*
  The statement typedef std::cout nameing; is not valid in C++
  because std::cout is an object (a global instance of std::ostream),
  not a type. The typedef keyword can only be used to create aliases
  for types, not objects.
*/
// typedef std::cout nameing;

// there is also another way to use this by using 

using string_t = std::string;
using number_t = int;
using character_t = char;
using decimalNum_t = double;


int main() {

  // TYPEDEFS and type aliases.
  // Typedefs allow you to give descriptive names to standard data types.
  // an type alias declaration to declare a name to use as a synonym for a 
  // previously declared type.

  string_t name = "Basit ";
  number_t num = 6 + 9;
  character_t grade = 'A';
  decimalNum_t gpa = 4.1;

  // for fun :)
  std::cout << name << num << " " << grade << " "  << gpa;

  /*
    that how u can use the typedef and type aliases 
    but it is more efficient using this using XD.s
   */

  return 0;
}