#include <iostream>

  // structs are u sed to group variables under one named structs 
  // and can obtain different datatypes.

  // variables in a structs are also called "member".
  // member can also be acces with . "Class Member Access Operator".

  // its kinda similar to objects if you a pro programmer

  // you can also state a default value in struct

  struct Games {
    std::string name;
    double price;
    double rating = 3.0;
  };

int main () {

  Games game1;
  game1.name = "GTA V";
  game1.price = 59.99;
  //game1.rating = 4.7;

  std::cout << game1.name << '\n';
  std::cout  << '$' << game1.price << '\n';
  std::cout << game1.rating << " Stars" << '\n';

  Games game2;
  game2.name = "GTA VI";
  game2.price = 109.99;
  //game2.rating = 5.0;

  std::cout << game2.name << '\n';
  std::cout  << '$' << game2.price << '\n';
  std::cout << game2.rating << " Stars" << '\n';

  return 0;
}