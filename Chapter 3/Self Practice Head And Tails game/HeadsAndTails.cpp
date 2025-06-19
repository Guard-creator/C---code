#include <iostream>
#include <ctime>

int main() {

  std::cout << "********** Heads and Tails Game **********\n";

  // havent learn local storage or how to save data.
  //int wins = 0;
  //int losses = 0;

  std::string guess;
  std::string coinLandedOn;
  char playerInput;

  do {
    std::cout << "Coin Is About To Flip pick Heads with 'h' or Tails with 't': ";
    std::cin >> playerInput;

    if(playerInput == 'h' || playerInput == 'H') {
      guess = "Heads";
    } else if (playerInput == 't' || playerInput == 'T') {
      guess = "Tails";
    } else {
      std::cout << "please Enter heads(h) or tails(t)\n";
    }
  } while(guess.empty());

  int randNum;
  srand(time(0));
  randNum = (rand() % 2) + 1;

  switch(randNum) {
    case 1: 
      coinLandedOn = "Heads";
      break;
    case 2: 
      coinLandedOn = "Tails";
      break;
  }

  if(guess == coinLandedOn) {
    std::cout << "You Pick " << guess << " and Coin Landed On " << coinLandedOn << '\n';
    std::cout << "You Win!!!\n";
    //wins++;
  } else {
    std::cout << "You Pick " << guess << " and Coin Landed On " << coinLandedOn << '\n';
    std::cout << "You Lose!!!\n";
    //losses++;
  }

  // havent learn local storage or how to save data.
  //std::cout << "Wins: " << wins << ", " << "Losses: " << losses << '\n'; 

  std::cout << "******************************************\n";

  return 0;
}