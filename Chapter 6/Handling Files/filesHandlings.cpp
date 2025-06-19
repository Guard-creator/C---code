#include <iostream>
#include <fstream>

// to handle files or read or write in c++ we use fstream
// it's like we are saving memory like local storage in javascript
// but instead we use files 

int main() {

  // This method does not get the pevious data 
  // means when you input and get the output then rerun the code again 
  // the preious data get's removed with a new one you will enter
  // to keep it stack you need to use append in next file :')

  std::string MyText;
  std::cout << "Enter Some text to view it later: ";
  std::getline(std::cin, MyText); // i write "I am I am"
  // remember in C++ when files is created to write it automatically opens the file to write  
  std::ofstream myFiles("writingbruh.txt"); // ofstream writes data on craeted files
  myFiles << MyText << ", ";
  myFiles.close(); // close the file

  std::string readingVarb;
  std::ifstream myReadFile("writingbruh.txt"); // it read from while and get data from there

  // you can also use a while a loop to print like this
    // while(getline(myReadFile, readingVarb)) {
    //  std::cout << readingVarb;
    // }
  // using loop you can read multiples lines
  
  // getline function
  // is used to read a line until it reach 
  // at a new line \n.
  // in first argument it's get files input 
  // then store it in a variable in a second arguments.. 
  getline(myReadFile, readingVarb);

  std::cout << readingVarb;

  return 0;
}