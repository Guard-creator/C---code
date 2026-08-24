#include <iostream>
#include <list>

// hashSet 
// hashmap, hashtable and hashset are same algorithm 
// just how it used are different 

// in Hashset Theory Based 
// it is used to stor large number of element

// we use integer to store values but iam gonna use string to store it 
// we dont give keys to store the value 
// but we create key with it 
// like we take string and turn charater to ASII table unicode 
// and sum it and according to that sum we find keys 
// but we dont stores keys 
// we store the value using that key(after the key is hash)

class Hashset {

  private:
    const static int size = 10;
    std::list<std::string> table[size];
  
  public:

    bool isEmpty();
    int hashFunction(std::string val);
    void insertion(std::string val);
    void deletion(std::string val);
    std::string search(std::string val);
    void printTable();

};

bool Hashset::isEmpty() {
  int cou = 0;
  for(int i = 0; i < size; i++) {
    cou += table[i].size();
  }
  return cou == 0;
} 

int Hashset::hashFunction(std::string val) {
  int uniCode = 0;
  for(char c : val) {
    uniCode += (int)c;
  }

  return uniCode % size;
}

void Hashset::insertion(std::string val) {

  int hashKey = hashFunction(val);
  auto& cell = table[hashKey];
  int SameKeyExist = false;
  for(auto itr = cell.begin(); itr != cell.end(); itr++) {
    if(*itr == val) {
      SameKeyExist = true;
      std::cout << "Sorry No dubilcates keys allows.\n";
      break;
    }
  } 

  if(!SameKeyExist) {
    cell.push_back(val);
    std::cout << "Value has been inserted.\n";
  }

  return;

}

void Hashset::deletion(std::string val) {

  int hashkey = hashFunction(val);
  auto& cell = table[hashkey];
  bool keyExist = false;
  for(auto itr = cell.begin(); itr != cell.end(); itr++) {
    if(*itr == val) {
      keyExist = true;
      itr = cell.erase(itr);
      std::cout << "Value has been delete.\n";
      break;
    }
  }

  if(!keyExist) std::cout << "Sorry but no such key is found.\n";

  return;

} 

std::string Hashset::search(std::string val) {

  int hashkey = hashFunction(val);
  auto& cell = table[hashkey];
  for(auto itr = cell.begin(); itr != cell.end(); itr++) {
    if(*itr == val) {
      return "Value Exist in the List.\n";
      break;
    }
  }

  return "Sorry, But the Value Doesn't exist.\n";

}

void Hashset::printTable() {

  for(int i = 0; i < size; i++) {
    if(table[i].size() == 0) continue;

    std::cout << i << ": ";

    for(auto itr = table[i].begin(); itr != table[i].end(); itr++) {
      std::cout << *itr << " ";
    }

    std::cout << '\n';

  }  

}

int main() {

  Hashset ht;

  if(ht.isEmpty()) {
    std::cout << "The List is Empty.\n";
  } else {
    std::cout << "The List is Not Empty.\n";
  }

  ht.insertion("Basit");
  ht.insertion("Peter");
  ht.insertion("Reyna");
  ht.insertion("Raze");
  ht.insertion("Gamer");
  ht.insertion("Charllote");
  ht.insertion("Pop");
  ht.insertion("Gamer");

  ht.deletion("Raze");
  ht.deletion("Pop");

  ht.printTable();

  if(ht.isEmpty()) {
    std::cout << "The List is Empty.\n";
  } else {
    std::cout << "The List is Not Empty.\n";
  }

  std::cout << ht.search("Gamer");
  std::cout << ht.search("Pop");

  return 0;
}