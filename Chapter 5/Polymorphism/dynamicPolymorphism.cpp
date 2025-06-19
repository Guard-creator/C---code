#include <iostream>

// dynamic polymorphism 
// you can also called it function overriding or virtual function

// This is a form of runtime polymorphism where a base class pointer or reference 
// can be used to call a function that is overridden in a derived class. The correct 
// function to call is determined at runtime based on the actual object type.

// From me... -> |

// overridng happen when derived class inherieted from base class 
// and same function name override the base class function means ignore the 
// function of base class and take from derived class

class Animal {
  // The virtual keyword allows this function to be
  //  overridden in derived classes.
  public: 
  void virtual speak() {
    std::cout << "Animal make a sound!!\n";
  }

};

class Dog : public Animal {

  // The override keyword (optional but recommended) 
  // ensures that the function is actually overriding 
  // a base class function.

  public:
  void speak () override {
    std::cout << "A dog say Woof!!\n";
  }
};

class Cat : public Animal {
  public: 
  void speak() override {
    std::cout << "A Cat say Meow!!\n";
  }
};


int main() {

  // If we call class functions normally (without pointers or references), there’s no polymorphism

  // The primary reason for using pointers or references is to achieve runtime polymorphism. 
  // This means that the decision about which function to call (base class or derived class) 
  // is made at runtime based on the actual object type, not the type of the pointer or reference.

  Animal *animal;
  Dog dog;
  Cat cat;

  animal = &dog;
  animal->speak();

  animal = &cat;
  animal->speak();

  // Here, the function call is resolved at runtime based on the 
  // actual object type (Derived).

  // when we call directly there is no polymorphism
  
  return 0;
}