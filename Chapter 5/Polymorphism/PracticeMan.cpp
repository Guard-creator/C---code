#include <iostream>

class Shape {
  public: 

  virtual double area() {
    return 0;
  }

};

class Rectangle : public Shape {
  private:
  double width, height;
  public: 

  Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
  };

  double area() override {
    return 3.14159 * width * height;
  }
  
};

class Circle : public Shape {

  private:
  double radius;
  public: 

  Circle(double radius) {
    this->radius= radius;
  };

  double area() override {
    return radius * radius;
  }

};

int main() {

  Shape *shape;
  Rectangle rectangle(78.65, 45.42);
  Circle circle(43.32);

  shape = &rectangle;
  std::cout << "Rectangle Area: " << shape->area() << '\n';

  shape = &circle;
  std::cout << "Circle Area: " << shape->area() << '\n';

  return 0;
}