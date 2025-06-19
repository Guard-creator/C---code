#include <iostream>

// made by some previous Exprience me :)

class Car {
  public:
  std::string brand;
  std::string model;
  int speed = 0;
  bool istruckOpen;

  Car(std::string brand, std::string model) {
    this->brand = brand;
    this->model = model;
  }

  void displayInfo() {

    std::string displayTruck = istruckOpen ? "Open" : "Closed"; 

    std::cout << '\n';
    std::cout << " Brand: " << brand << ", " << "Model: " << model << ", " 
    << '\n' << "Speed: " << speed << "km/h" << " " << "Truck: " << displayTruck << '\n';
    std::cout << '\n';
  }

  void go() {

    if(!istruckOpen) {
      speed += 5;
    }

    if(speed > 200) {
      speed = 200;
    }
  }

  void brake() {
    speed -= 5;
    if(speed < 0) {
      speed = 0;
    }
  }

  void truckOpen() {

    if(speed > 0) {
      return;
    }

    istruckOpen = true;
  } 

  void truckClose() {
    istruckOpen = false;
  }

};

int main() {

  Car car1{"Toyota", "Corolla"};
  Car car2{"Tesla", "Model 3"};


  car1.go();
  car1.truckOpen();
  car1.go();
  car1.truckOpen();
  car1.brake();
  car1.truckOpen();
  car1.go();
  car1.brake();
  car1.truckClose();
  car1.go();
  car1.displayInfo();
  
  car2.go();
  car2.truckOpen();
  car2.go();
  car2.truckOpen();
  car2.go();
  car2.brake();
  car2.truckClose();
  car2.go();
  car2.displayInfo();

  return 0;
}