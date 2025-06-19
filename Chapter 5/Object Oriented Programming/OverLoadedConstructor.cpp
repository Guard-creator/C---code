#include <iostream>

// Called Constructor Overloading
// kinda same as function overloading. 

// We can have more than one constructor in a class with same name, 
// as long as each has a different list of arguments

// like the the part about this.....

using string = std::string;

class Books{
  public:

  string author;
  string name;
  double price;

  // all Constructor name are same 
  // and it should be 
  // but each with different argument is working differently..
  Books(string author) {
    this->author = author;
    std::cout << "Author: " << author << '\n';
    std::cout << '\n';
  }

  Books(string author, string name) {
    this->author = author;
    this->name = name;
    std::cout << "Author: " << author << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << '\n';
  }

  Books(string author, string name, double price) {
    this->author = author;
    this->name = name;
    this->price = price;
    std::cout << "Author: "<< author << '\n';
    std::cout << "Name: "<< name << '\n';
    std::cout << "Price: " << price << '\n';
    std::cout << '\n';
  }
  
};

int main() {

  Books book1("RobinSon");
  Books book2("David Joggens", "Never let me Down");
  Books book3("Unkown", "Zero to Hero", 59.88);
 
  return 0;  
}