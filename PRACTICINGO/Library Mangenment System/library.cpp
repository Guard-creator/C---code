#include <iostream>
#include <fstream>
#include <vector>

class Book {
  public:
  std::string title;
  std::string author;
  std::string ISBN;
  bool isAvailable;

  Book(std::string t, std::string a, std::string isbn) : 
  title(t), author(a), ISBN(isbn), isAvailable(true) {};

  void Display() const {
    std::cout << "Title: " << title << ", Author: " << 
    author << ", ISBN: " << ISBN << ", " << (isAvailable ? "Available" : "Not Available") << '\n';
  }

};

class Library {
  private:
    std::vector<Book> books;
  public:

  void addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Book is Added Successfully.\n";
  }

  void displayAllBook() const {
    if(books.empty()) {
      std::cout << "Library is Currently Empty Right Now.\n";
      return;
    }
    for(const auto& book : books) {
      book.Display();
    }
  }

  void searchBook(const std::string& query) {
    bool found = false;
    for(const auto& book : books) {
      if(book.title == query || book.author == query  || book.ISBN == query) {
        book.Display();
        found = true;
      }
    }
    if(!found) {
      std::cout << "No Matching Book is Found.\n";
    }
  }

  void issueBook(const std::string& ISBN) {
    for(auto& book : books) {
      if(book.ISBN == ISBN) {
        if(book.isAvailable) {
          book.isAvailable = false;
          std::cout << "Book Is Issued Successfully.\n";
        } else {
          std::cout << "Book is Already Issued.\n";
        }
        return;
      }
    }
    std::cout << "No Matching Book is Found.\n";
  }

  void returnBook(const std::string& ISBN) {
    for(auto& book : books) {
      if(book.ISBN == ISBN) {
        if(!book.isAvailable) {
          book.isAvailable = true;
          std::cout << "Book Is Return Successfully.\n";
        } else {
          std::cout << "Book is Already Return.\n";
        }
      }
    }
  }

  void deleteBook(const std::string& ISBN) {
    for(auto it = books.begin(); it != books.end(); it++) {
      if(it->ISBN == ISBN) {
        books.erase(it);
        std::cout << "Book Is Delete Successfully.\n";
        return;
      }
    }
    std::cout << "No Matching Book is Found.\n";
  }

  void saveIntoFile(const std::string& fileName) {

    std::ofstream file(fileName);
    
    for(const auto& book : books) {
      file << book.title << ',' << book.author 
      << ',' << book.ISBN << ',' << book.isAvailable << '\n';
    }

    std::cout << "Library Data is Saved in Files Successfully\n";

  }

  void loadIntoFile(const std::string& fileName) {

    std::ifstream file(fileName);

    if(!file) {
      std::cout << "FIle Does Not Exist";
      return;
    }

    books.clear();
    std::string line;
    while(std::getline(file, line)) {

      std::string title, author, ISBN;

      size_t pos1 = line.find(',');
      size_t pos2 = line.find(',', pos1 + 1);
      size_t pos3 = line.find(',', pos2 + 1);

      title = line.substr(0, pos1);
      author = line.substr(pos1 + 1, pos2 - pos1 - 1);
      ISBN = line.substr(pos2 + 1, pos3 - pos2 - 1);
      bool isAvailable = (line.substr(pos3 + 1) == "1");

      books.push_back(Book(title, author, ISBN));
      books.back().isAvailable = isAvailable;

    }

  }

};

int main() {

  Library library;
  int choice;
  std::string fileName = "library_data.txt";
  library.loadIntoFile(fileName);

  while(true) {
    std::cout << "L I B R A R Y  M A N G E M E N T  S Y S T E M\n";
    std::cout << "1. Add Books\n";
    std::cout << "2. Display All Book\n";
    std::cout << "3. Search Book\n";
    std::cout << "4. Issue Book\n";
    std::cout << "5. Return Book\n";
    std::cout << "6. Delete Book\n";
    std::cout << "7. Save and Exit\n";
    std::cout << "Enter Your Choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
      case 1: {
        std::string title, author, ISBN;
        std::cout << "Enter Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, author);
        std::cout << "Enter ISBN: ";
        std::getline(std::cin, ISBN);
        library.addBook(Book(title, author, ISBN));
        break;
      }

      case 2:
        library.displayAllBook();
        break;

      case 3: {
        std::string query;
        std::cout << "Enter Title, Author, or ISBN: ";
        std::getline(std::cin, query);
        library.searchBook(query);
        break;
      }

      case 4: {
        std::string ISBN;
        std::cout << "Enter ISBN of the Book to Issue: ";
        std::getline(std::cin, ISBN);
        library.issueBook(ISBN);
        break;
      }

      case 5: {
        std::string ISBN;
        std::cout << "Enter ISBN of the Book to Return: ";
        std::getline(std::cin, ISBN);
        library.returnBook(ISBN);
        break;
      }

      case 6: {
        std::string ISBN;
        std::cout << "Enter ISBN of the Book to Delete: ";
        std::getline(std::cin, ISBN);
        library.deleteBook(ISBN);
        break;
      }

      case 7: 
        library.saveIntoFile(fileName);
        std::cout << "Exiting The System. GOODBYE!!\n";
        return 0;

      default:
        std::cout << "Invalid Choice! Please Try Again!\n";
    }
  }

  return 0;
}