#include <iostream>

// inheritance is same as i learn 
// the class when it is inheriting its attribute & method 
// from an another class is called inheritance.

class Animal {
  public:
    bool alive = true;
    void eating() {
      std::cout << "Yess Iam eating..!\n";
    }

};

class Bird : public Animal {
  public:
  std::string type = "Iam Bird!";
  int legs = 2;

};

class Dog : public Animal {
  public:
  std::string type = "What da Dog Doin ?? !";
  int legs = 4;

};

int main() {

  Bird bird1;
  Dog dog1;

  std::cout << bird1.alive << '\n';
  bird1.eating();
  std::cout << bird1.type << '\n';
  std::cout << "Legs: " << bird1.legs << '\n';

  std::cout << dog1.alive << '\n';
  dog1.eating();
  std::cout << dog1.type << '\n';
  std::cout << "Legs: " << dog1.legs << '\n';

  return 0;
}