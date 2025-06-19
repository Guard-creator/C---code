#include <iostream>
#include <limits>
#include <vector>

// Create a program to store student details dynamically and print them.
// its deepseek help a lot.

struct StudentDetails {
  std::string names;
  int age;
  double gpa;
};

int main() {
  int noOfStudents;

  std::cout << "Enter Number of Students #: ";
  std::cin >> noOfStudents;

  std::vector<StudentDetails> students(noOfStudents);

  for(int i = 0; i < noOfStudents; i++) {
    std::cout << "Enter Students details of #" << i + 1 << '\n';
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Name: ";
    std::getline(std::cin, students[i].names);
    
    std::cout << "Age: ";
    std::cin >> students[i].age;
    
    std::cout << "Gpa: ";
    std::cin >> students[i].gpa;
  }

  for(int i = 0; i < noOfStudents; i++) {
    std::cout << "=================================\n";
    std::cout << "Student No " << i + 1 << '\n';
    std::cout << "Name: " << students[i].names << '\n'; 
    std::cout << "Age: " << students[i].age << '\n'; 
    std::cout << "Gpa: " << students[i].gpa << '\n'; 
    std::cout << "=================================\n";
  }

  return 0;
}
