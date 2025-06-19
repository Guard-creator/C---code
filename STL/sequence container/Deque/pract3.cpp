#include <iostream>
#include <deque>
#include <sstream>

int main() {

  std::deque<int> dq;
  std::string command;
 

  while(true) {

    std::cout << "Enter (push_front X, push_back X, pop_front, pop_back, print, exit): ";
    std::getline(std::cin, command);
  
    std::stringstream ss(command);
    
    std::string operation;
    int value;

    ss >> operation;

    if(operation == "push_front") {
      if(ss >> value) {
        dq.push_front(value);
      } else {
        std::cout << "Invalid command expect Number after push_front.\n";
      }
    } else if(operation == "push_back") {
      if(ss >> value) {
        dq.push_back(value);
      } else {
        std::cout << "Invalid command expect Number after push_back.\n";
      }
    } else if(operation == "pop_front") {
      if(!dq.empty()) dq.pop_front();
    } else if(operation == "pop_back") {
      if(!dq.empty()) dq.pop_back();
    } else if(operation == "print") {
      for(int element : dq) { std::cout << element << " "; }
      std::cout << '\n';
    } else if(operation == "exit") {
      break;
    } else {
      std::cout << "Invalid Input.\n";
    }
    
  }

  return 0;
}