#include <iostream>

struct Student {
  std::string names;
  int age;
  char grade;
};

int main() {

  int numStudents;

  std::cout << "Enter the Number of Students: ";
  std::cin >> numStudents;

  Student * student = new Student[numStudents];

  for(int i = 0; i < numStudents; i++) {

    std::cout << "Enter Details of Number " << i + 1 << '\n';
    std::cout << "Names: ";
    std::cin.ignore();
    std::getline(std::cin, student[i].names);
    std::cout << "Age: ";
    std::cin >> student[i].age;
    std::cout << "Grade: ";
    std::cin >> student[i].grade;

  }

  std::cout << "-------------------------------------\n";

  for(int i = 0; i < numStudents; i++) {

    std::cout << "Students Number " << i + 1 << '\n';
    std::cout << "Names: " << student[i].names << '\n';
    std::cout << "Age: " << student[i].age << '\n';
    std::cout << "Grade: " << student[i].grade << '\n';

  }

  std::cout << "-------------------------------------\n";

  delete[] student;
  student = nullptr;

  return 0;
}