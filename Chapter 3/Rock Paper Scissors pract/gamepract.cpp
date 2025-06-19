#include <iostream>
#include <ctime>

// i created this in my own.

using string = std::string;

char playerChoosen();
char computerMove();
string displayBothPicks(char displayMoves);
void checkWinner(char playerPick, char computerPick);

int main () {

  std::cout << "****************************************************\n";
  std::cout << "**            ROCK PAPER SCISSORS GAME            **\n";
  std::cout << "****************************************************\n";

  char playerPick = playerChoosen();
  char computerPick = computerMove();

  string computerDisp = displayBothPicks(computerPick);
  string playerDisp = displayBothPicks(playerPick);

  std::cout << playerPick << " " << computerPick << '\n';

  std::cout << "You pick " << playerDisp << " Computer pick " << computerDisp << '\n';

  checkWinner(playerPick, computerPick);

  return 0;
}

char playerChoosen() {

  char playerPick;

  do {
      std::cout << "**************************\n";
      std::cout << "*    CHOOSE YOUR MOVE    *\n";
      std::cout << "**************************\n";
      std::cout << "'r' for Rock\n" ;
      std::cout << "'p' for Paper\n";
      std::cout << "'s' for Scissors\n";
      std::cin >> playerPick;

      switch (playerPick) {
        case 'r': return playerPick;
        case 'p': return playerPick;
        case 's': return playerPick;
        default : std::cout << "Invalid Choice\n";
      }
  } while (playerPick != 'r' || playerPick != 'p' ||playerPick != 'r');

  return 0;

}

char computerMove() { 

  char computerPick;

  srand(time(0));

  int randNum = (rand() % 3) + 1;

  switch (randNum) {
    case 1: return computerPick = 'r';
    case 2: return computerPick = 'p';
    case 3: return computerPick = 's';
    default: return 0; // never reached here.
  }

}

string displayBothPicks(char displayMoves) {

  string moveDisplay;
  
  switch (displayMoves) {
    case 'r': moveDisplay = "Rock";
              break;
    case 'p': moveDisplay = "Paper";
              break;
    case 's': moveDisplay = "Scissors";
              break;
  }

  return moveDisplay;

}

void checkWinner(char playerPick, char computerPick) {

  if(playerPick == 'r') {

      if(computerPick == 'r') {
          std::cout << "Ties\n";
      } else if(computerPick == 'p') {
          std::cout << "You Lose!!!\n";
      } else if (computerPick == 's') {
          std::cout << "You Win!!!\n";
      }
      
  } else if (playerPick == 'p') {

      if(computerPick == 'r') {
          std::cout << "You Win!!!\n";
      } else if(computerPick == 'p') {
          std::cout << "Ties\n";
      } else if (computerPick == 's') {
          std::cout << "You Lose!!!\n";
      }

  } else if (playerPick = 's') {

      if(computerPick == 'r') {
          std::cout << "You Lose!!!\n";
      } else if(computerPick == 'p') {
          std::cout << "You Winn!!!\n";
      } else if (computerPick == 's') {
          std::cout << "Ties\n";
      }

  }

}