#include <iostream>

// object oriented programming 
// just like in javascripts each class are used like as purpose 
// we use classes just like in javascripts

// Each Class have attribute and methods
// like a mobile, its attribute its name, model, chips,
// and methods are what kinds for things that mobile can do 
// like take selfies or play games use social media.

// this is jsut my way of thinging how object oriented language works.

class Car {
  // it should be assigned public at first otherwise its will be private.
  public:

  // you can also assigned names in the main function 
  // in here its default value 
  // i just want one car that's why i did it default.

  std::string brand = "Toyota";
  std::string model = "Model 3";

  int speed = 0;

  void displayInfo() {
    std::cout << "Brand: " << brand << '\n';
    std::cout << "Model: " << model << '\n';
    std::cout << "speed: " << speed << "m/s" << '\n';
  }

  void accelerateCar() {
    speed += 20;
  }

  void brakeCar() {
    speed -= 10;
  }

};

int main() {

  // this is a object like a car. same car my friendo XD
  Car car1;

  car1.accelerateCar();
  car1.accelerateCar();
  car1.accelerateCar();
  car1.brakeCar();

  car1.displayInfo();
  

  return 0;
}