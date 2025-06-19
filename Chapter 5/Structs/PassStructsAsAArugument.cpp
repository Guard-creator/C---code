#include <iostream>

// i can understand the everything

struct Cars {
  std::string name;
  int horsePower;
};

void printCars(Cars &car);
void ChangePower(Cars &car, int maxHorsePower);

int main() {

  // you can choose either to set a value 
  // i learn the first one at chatpt.

  Cars car1 = {"Corolla", 300};

  Cars car2;
  car2.name = "Swift";
  car2.horsePower = 600;

  ChangePower(car1, 800);

  printCars(car1);
  printCars(car2);

  return 0;
}

void printCars(Cars &car) {
  std::cout << car.name << '\n';
  std::cout << car.horsePower << '\n';
}

void ChangePower(Cars &car, int maxHorsePower) {
  car.horsePower = maxHorsePower;
}
