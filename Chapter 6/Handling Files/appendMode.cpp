#include <iostream>
#include <fstream>

// now using append mode you an keep ther previous data as well as the next 
// data 
// You need to open the file with std::ios::app to ensure 
// new content is always added at the end.
// std::ios::app always open the file in append mode


int main() {

  // this code will keep stacking data into same file.

  // std::ofstream append("writefile.txt", std::ios::app);
  // append << "This is empty files!\n";

  std::ofstream writeFile("data.txt", std::ios::app);

  std::string userInput;
  std::cout << "Enter Anything: ";
  std::getline(std::cin, userInput);
  writeFile << userInput << '\n';
  writeFile.close();
  std::cout << "Data write Successfully\n";

  std::string line;
  std::ifstream readFile("data.txt");
  std::cout << "Current File Content: \n";
  while(std::getline(readFile, line)) {
    std::cout << line << '\n';
  }
  readFile.close();

  return 0;
}