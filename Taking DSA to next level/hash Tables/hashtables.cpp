#include <iostream>
#include <list>

// HASHTABLES 
// A Hash Table is a data structure designed to be fast to work with.

// The reason Hash Tables are sometimes preferred instead of arrays or linked lists 
// is because searching for, adding, and deleting data can be done really quickly, even
// for large amounts of data.

// With a Hash Table however, finding a value is done really fast because 
// there is a way to go directly to where a value is stored, using something called a hash function.

// we use linked list for fast insertion and deletion 
// this list consist of pairs with keys and it's value

// we give an list a fixed size
// it be easy to get index of each key cuz we can module or find it's remainder

// Now what if we get same index?
// when we use hashfunction to get an hashvalue aka Index
// there is an chance of getting the same index where the value stores already
// This is Called Collision
// We handle this in Two ways:
// Separate Chaining
// Open Addressing 

// Separate Chaining
// separate chaining is an technique where each index of the table stores a linked list of elements.
// if an collision happen we take that value and push it in the same index 
// making a list like this 
// index: 1 →  [ "Guard" → "Rea" → "jakes" ]

// Open Addressing 
// In open addressing when collision happen it takes that value and put it in next index
// if that index is also occupied we put it in next index until an empty slot is found
// If index 5 is full, try 6, then 7, then 8, ...

// THIS IS THE IMPLEMENTATION OF SEPARATE CHAINING
// 
// Thanks for Coding Jesus (getcracked.io) yt videos 
// it helps alot :)

class hashtable {

  private:
    static const int size = 10; // fixed size
    std::list<std::pair<int, std::string>> table[size];

  public:

  bool isempty();
  int hashfunction(int key);
  void insertion(int key, std::string value);
  void deletion(int key);
  std::string search(int key);
  void printTable();

};

bool hashtable::isempty() {
  int sum = 0;
    for(int i = 0; i < size; i++) {
      sum += table[i].size();
    }

    return sum == 0;
} 

int hashtable::hashfunction(int key) {
  return key % size; // give an index in that range of size
}

void hashtable::insertion(int key, std::string value) {

  int hashkey = hashfunction(key);
  auto& cell = table[hashkey];
  bool keyExist = false;
  for(auto itr = begin(cell); itr != end(cell); itr++) {
    if(itr->first == key) {
      itr->second = value;
      keyExist = true;
      std::cout << "Key Exists, Value Replace.\n";
      break;
    }
  }

  if(!keyExist) {
    cell.emplace_back(key, value);
  }
  return;
}

void hashtable::deletion(int key) {

  int hashkey = hashfunction(key);
  auto& cell = table[hashkey];
  bool keyExist = false;
  for(auto itr = begin(cell); itr != end(cell); itr++) {
    if(itr->first == key) {
      keyExist = true;
      itr = cell.erase(itr);
      std::cout << "Value Removed.\n";
      break;
    }
  }

  if(!keyExist) std::cout << "Key doesn't exist.\n";

  return;

}

std::string hashtable::search(int key) {
  int hashkey = hashfunction(key);
  auto& cell = table[hashkey];
  for(auto itr = cell.begin(); itr != cell.end(); itr++) {
    if(itr->first == key) {
      return itr->second;
    }
  } 

  return "Key doesn't exist.\n";
}

void hashtable::printTable() {

  for(int i = 0; i < size; i++) {
    if(table[i].size() == 0) continue;

    for(auto itr = table[i].begin(); itr != table[i].end(); itr++) {
      std::cout << i << ". Key: " << itr->first << ", Value: " << itr->second << '\n'; 
    }
  }

}


int main() {

  hashtable ht;

  if(ht.isempty()) {
    std::cout << "Table is Empty.\n";
  } else {
    std::cout << "Table is Not Empty.\n";
  }

  ht.insertion(201, "Raze");
  ht.insertion(156, "Guard");
  ht.insertion(873, "Pame");
  ht.insertion(972, "Neon");

  ht.deletion(156);
  
  ht.printTable();

  std::cout << ht.search(972) << '\n';
  std::cout << ht.search(131) << '\n';

  if(ht.isempty()) {
    std::cout << "Table is Empty.\n";
  } else {
    std::cout << "Table is Not Empty.\n";
  }

  

  return 0;
}