#include <iostream>

class Shape {
  public:
  double area;
  double volume;
};

class Cube : public Shape {
  public:

  double side;
  Cube(double side) {
    this->side = side;
    this->area = side * side * 6;
    this->volume = side * side * side;
  }

};

class Sphere : public Shape {
  public:

    double radius;

  Sphere(double radius) {
    this->radius = radius;
    this->area = 4 * 3.14159 * (radius * radius);
    this->volume = (4/3.0) * 3.14159 * (radius * radius * radius);
  }

};

int main() {

  Cube cube(10);

  std::cout << '\n';
  std::cout << "Area: " << cube.area << '\n';
  std::cout << "Volume: " << cube.volume << '\n';
  std::cout << '\n';

  Sphere sphere(10);

  std::cout << '\n';
  std::cout << "Area: " << sphere.area << '\n';
  std::cout << "Volume: " << sphere.volume << '\n';
  std::cout << '\n';

  return 0;
}