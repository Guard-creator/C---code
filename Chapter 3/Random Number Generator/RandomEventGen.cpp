#include <iostream>
#include <ctime>

int main() {
  
  // generating random event o even a computer program that take dicision.

    srand(time(NULL));

    int randomnumber = (rand() % 2) + 1;

    if(randomnumber == 1) {
      std::cout << "Head's";
    } else if (randomnumber == 2) {
      std::cout << "Tail's";
    }

  /*
    srand(time(NULL));

    int RanNum = (rand() % 5) + 1;

    switch (RanNum) {
      case 1: std::cout << "You Win a FootBall.";
              break;
      case 2: std::cout << "You Win Consert Tickets.";
              break;
      case 3: std::cout << "You Win a Mobile Phone";
              break;
      case 4: std::cout << "You Win a glasses";
              break;
      case 5: std::cout << "You Win a Bloody Mouse";
              break;
    }
  */

  return 0;
}