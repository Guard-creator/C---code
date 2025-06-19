#include <iostream>

// The meaning of Encapsulation, is to make sure that 
// "sensitive" data is hidden from users
// we use "Gettes" & "Setters" function that are assigned in
// class to view or change the private data...

class Books {

  private:
  // we dont want anyone to pass with orignal data.
    std::string author = "David Joggin's";
  public:
  // but if need we can change using Get and Set function
  // heres how.

  // you can view...
  std::string getAuthor() {
    return author;
  }

  // you can change
  void setAuthor(std::string author) {
    this->author = author;
  }

};

int main() {

  Books book1;

  // its private so nobody can access it directly so 
  // over orginal data is save...
  //book1.author = "Me";

  // using getter and setter..

  std::cout << book1.getAuthor() << '\n';

  book1.setAuthor("Me");

  std::cout << book1.getAuthor() << '\n';

  return 0;
}