#include <iostream>
#include <vector>

// In C++, a vector is a dynamic array provided by the Standard Template Library (STL).
// It is a sequence container that can change its size dynamically, meaning it can grow 
// or shrink as needed. Vectors are similar to arrays, but they offer more flexibility
// and functionality.

// they are like array but more advance and with more function.

// to use vector we have include the header file. #include <vector>

// vector also get double is capacity when when we input a element 
// size = number of element [1] [2] // 2
// capacity = number of element it can hold [1] [2] [] [] // 4

// find the  capacity using function .capacity();

int main() {

  // that how we can declare a vector now or later you can assign value
  std::vector<std::string> games;
  // or create a vector with size and dont declare it maybe later
  std::vector<int> anime(10, 0);

  // like here we assign the value.
  games = {"Elden Ring", "Genshin Impact", "Valorant"};

  // You can also modify vector directly 
  games[0] = "Pubg";  

  // and iterate over like this 
  // using size() function we can 
  // find length of vector
  for(int i = 0; i < games.size(); i++) {
    std::cout << i + 1 << ". " << games[i] << '\n';
  } 

  return 0;
}