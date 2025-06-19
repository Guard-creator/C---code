#include <iostream>

int main() {

  // switches are like if statements 
  //  take a example from down below
  // code is written like yandere simulator and we dont want that that's why we use switches.
  /*
      char grade;

      std::cout << "Please Enter your Grades: ";
      std::cin >> grade;

      if(grade == 'A') { 
        std::cout << "your did pretty well";
      } else if (grade == 'B') {
        std::cout << "you did well";
      } else if (grade == 'C') {
        std::cout << "you did well";
      } else if (grade == 'D') {
        std::cout << "you did not do well";
      } else if(grade == 'F') {
        std::cout << "YOu FAILED!";
      } else {
        std::cout << "please enter your grade (A-F)";
      }
  */

    int month;

    std::cout << "Please enter an month in number: ";
    std::cin >> month;

    switch (month) {
      case 1:
        std::cout << "Its January";
        break;
      case 2:
        std::cout << "Its Febuary";
        break;
      case 3:
        std::cout << "Its March";
        break;
      case 4:
        std::cout << "Its April";
        break;
      case 5:
        std::cout << "Its May";
        break;
      case 6:
        std::cout << "Its June";
        break;
      case 7:
        std::cout << "Its July";
        break;
      case 8:
        std::cout << "Its August";
        break;
      case 9:
        std::cout << "Its Setember";
        break;
      case 10:
        std::cout << "Its Octuber";
        break;
      case 11:
        std::cout << "Its November";
        break;
      case 12:
        std::cout << "Its December";
        break;
      default: 
        std::cout << "Please put Month in number (1-12)";
        break;
    }
  

  return 0;
}