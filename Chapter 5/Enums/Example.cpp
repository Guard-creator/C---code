#include <iostream>

enum Rank {BEGINNER = 100, INTERMEDIATE = 200, ADVANCED = 300};

int main() {

  int playerRank;

  std::cout << "Enter Your Rank: ";

  if(!(std::cin >> playerRank)) {
    std::cout << "Invalid input! Please enter a number.\n";
    return 1;
  };

  Rank rank;

  if(playerRank >= 0 && playerRank <= BEGINNER) {
    std::cout << "You are a Beginner!!!\n";
  } else if(playerRank >= BEGINNER && playerRank <= INTERMEDIATE) {
    std::cout << "You are a Intermediate!!!\n";
  } else if(playerRank >= INTERMEDIATE && playerRank <= ADVANCED) {
    std::cout << "You are a Advanced!!!\n";
  } else {
    std::cout << "Please Enter a Valid RanK (0 - 300)\n";
  }

  return 0;
}