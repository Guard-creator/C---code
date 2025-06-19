#include <iostream>
#include <vector>

// Function Declaration

std::string addTodo();
void deleteTodo(std::vector<std::string> & todoList);
void viewTodo(const std::vector<std::string> & todoList);

int main() {

  std::vector<std::string> todoList = {"Should Eat Everyday"};

  int userInput;

  std::cout << "********************************\n";
  
  std::cout << "Press '1' to Add Todo\n";
  std::cout << "Press '2' to Delete Todo\n";
  std::cout << "Press '3' to Exit\n";

  std::cout << "********************************\n";

  viewTodo(todoList);

  do {

    std::cout << "Select the Option: ";

    while(!(std::cin >> userInput)) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Invalid Input.. Please Enter a Number(1, 2, or 3): ";
    }

    switch (userInput) {
    case 1: 
      todoList.push_back(addTodo());
      viewTodo(todoList);
      break;
    case 2: 
      deleteTodo(todoList);
      viewTodo(todoList);
      break;
    case 3:
      std::cout << "Make Sure to do it on Time :)\n";
      break;
    }

  } while(userInput != 3);

  return 0;
}

std::string addTodo() {

  std::string temp;
  std::cin.ignore(10000, '\n');
  std::cout << "Add an Todo: ";
  std::getline(std::cin, temp);

  return temp;

}
void deleteTodo(std::vector<std::string> & todoList) {

  if(todoList.empty()) {
    std::cout << "Todo List is Empty\n";
    return;
  }

  int userInput;

  std::cout << "Which Todo You want Remove: ";
  std::cin >> userInput;

  if(std::cin.fail() || userInput < 1 || userInput > todoList.size()) {
    std::cin.clear(); // clear error Flags
    std::cin.ignore(10000, '\n'); // discard invalid input
    std::cout << "Invalid input, Please Enter the Valid Input\n";
    return;
  }

  todoList.erase(todoList.begin() + (userInput - 1));

  std::cout << "Todo is SuccessFully Delete\n";

}
void viewTodo(const std::vector<std::string> & todoList) {

  std::cout << "-----------------------------------\n";
  std::cout << " T O D O  -  L I S T \n";

  if(!todoList.empty()) {
    for(int i = 0; i < todoList.size(); i++) {
      std::cout << i + 1 << ". " << todoList[i] << '\n';
    }
  } else {
    std::cout << "No Todo Avaiable..\n";
  }

  std::cout << "-----------------------------------\n";

}
