#include <iostream>

int main(){

  // Data types and variables

  // int = integer (it can be any whole number)
  // int cant save number that have decimal if 
  // we try to it will get truncated or get stortend

  int age = 18;
  int year = 2025;
  int days = 3.8;

  // in this case we can use double that include decimal.

  double price = 8.99;
  double gpa = 4.01;
  double temperature = 10.3;

  // another data type we can use is  'char' that can store a single character

  char currency = '$';
  char gradeOfStudent1 = 'A';
  char gradeOfStudent2 = 'B';

  // boolean, in cpp bool are named to represent  a value for suppose 
  // boolean can eithe be false or true
  // another think if you notice if you try to cout boolean value
  // its show true(1) or false(0);
  
  bool power = true;
  bool electicity = false;

  // another data type is string
  // sting are provide from std namespace with a differnt syntax
  
  std::string studentName = "Basit shaikh";
  std::string day = "sunday";
  std::string favFood = "fried chicken";

  std::cout << "hello "<< studentName << '\n';
  std::cout << "You are " << age << " years old" << '\n';
  
  
  /*
  int x;
  x = 34234;
  int y = 2312;

  int sum = x + y;

  std::cout << x << '\n';
  std::cout << y << '\n';
  std::cout << sum << '\n';
  */

  return 0;

}