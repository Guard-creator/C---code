#include <iostream>

using string = std::string;

int main() {

  string questions[] = {"1. When pakistan got freedom?: ",
                        "2. Who Invented C++?: ",
                        "3. What is the predecessors of C++?: ",
                        "4. Are you Born yet?: "};
                            

  string options[][4] = {{"A. 1946", "B. 1947", "C. 1945", "D. 1948"},
                        {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmark", "D. Mark Zuckerburg"},
                        {"A. C", "B. C--", "B++", "D. C+"},
                        {"A. Yes", "B. No", "C. Never", "D. What??"}};

  char answerKey[] = {'B', 'B', 'A', 'A'};

  int size = sizeof(questions)/sizeof(questions[0]);
  char guess;
  int score = 0;

  for(int i = 0; i < size; i++) {

    std::cout << "****************************\n";
    std::cout << questions[i] << '\n';
    std::cout << "****************************\n";

    for(int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++) {
      std::cout << options[i][j] << '\n';
    }

    std::cin >>guess;
    guess = toupper(guess);

    if(guess == answerKey[i]) {
      std::cout << " CORRECT" << '\n';
      score++;
    } else {
      std::cout << "WRONG!!" << '\n';
      std::cout << "Answer: " << answerKey[i] << '\n';
    }

  }

  std::cout << "**************************\n";
  std::cout << "*         RESULTS        *\n";
  std::cout << "**************************\n";
  std::cout << "CORRECT GUESSES: " << score << '\n';
  std::cout << "No of Questions: " << size << '\n';
  std::cout << "SCORE: " << (score/(double)size)*100 << "%" << '\n'; 

  return 0; 
}