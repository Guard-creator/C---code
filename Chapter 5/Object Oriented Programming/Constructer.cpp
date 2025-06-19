#include <iostream>

// Constructor are used to pass attribute 
// idt i need to talk about it more 
// easy pretty simple/

class AttendenceCheck {
  public:
  std::string name;
  int attend;
  int totalAttendence = 200;

  // we have to use this-> 
  // because if the attribute in class
  // and constructor aruguement are same
  // you have to used this-> otherwise 
  // you can just pass directly
  // name = (different Name)ConstructorName
  AttendenceCheck(std::string name, int attend) {
    this->name = name;
    this->attend = attend;
  };

  void displayInfo() {
    std::cout << "=======================================\n";
    std::cout << "Name: " << name << '\n';
    std::cout << "Attendence: " << attend /(double) totalAttendence * 100 << "%" <<  '\n';
    std::cout << "=======================================\n";
  };

};

int main() {

  std::string name;
  int attend;

  std::cout << "<<<<<<< CHECK ATTENDENCE >>>>>>>\n";
  std::cout << "Enter Your Name: ";
  std::cin >> name;
  std::cout << "How many Classes You Have Attend: ";
  std::cin >> attend;

  AttendenceCheck student1(name, attend);
  student1.displayInfo();

  return 0;
}