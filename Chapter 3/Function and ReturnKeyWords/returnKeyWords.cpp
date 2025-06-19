#include <iostream>

// function can also return value  
// same as i have studied before

using string = std::string;

double square(double length);
double cube(double length);
string namingYourself(string firstName, string LastName);

int main() {

  double length = 6.0;

  string firstName = "Basit";
  string LastName = "Shaikh";
  string fullName = namingYourself(firstName, LastName);

  double squareResult = square(length);
  double cubeResult = cube(length);

  std::cout << squareResult << "cm^2\n";
  std::cout << cubeResult << "cm^2\n";
  std::cout << fullName <<  '\n';

  return 0;
}

double square(double length) {
  return length * length;
}

double cube(double length) {
  return length * length * length;
}

string namingYourself(string firstName, string LastName) {
  return firstName + " " + LastName;
}

