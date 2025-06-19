#include <iostream>

int main() {

  // WHILE LOOP 

  // a While is like like a if statement and which will run 
  // the code repeatly until the statement is becomes false.

  /*
    std::string name;

    while(name.empty()) {
      std::cout << "please Enter Your Name: ";
      std::getline(std::cin, name);
    }

    std::cout << "I love You " << name;
  */

  /*
    int num = 0;

    while(num < 100) {
      std::cout << num << '\n';
      num+=1;
    }
  */

  // DO WHILE LOOP

  // do while loop we run the code first then check the statment is true or false
  
  /*
    int num;

    do {
      std::cout << "Enter a Number: ";
      std::cin >> num;
    } while(num < 0);

    std::cout << "The Number is: " << num;
  */

  /*
    std::string password;
    std::string SavedPasskey = "BasitShaikh";

    do{
      std::cout << "Enter Your Correct PassWord: ";
      std::cin >> password;
    }while(password != SavedPasskey);

    std::cout << "The Password is Correct it was " << SavedPasskey;
  */

  // FOR LOOPS

  // This Code will repeat until the statement or condition is met 

  /*
    for(int i = 10; i >= 0; i-=2) {
      std::cout << i << '\n';
    }
  */

    int num;

    std::cout << "Which Table would you like to see: ";
    std::cin >> num;

    if(num > 20 || num < 0) {
      std::cout << "you can only enter the number (1 to 20)";
      return 1;
    }  

    for (int i = 1; i <= 10; i++) {
      std::cout << num << " x " << i << " = " << num * i << '\n';
    }
  

  return 0;
}