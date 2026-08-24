#include <iostream>

// Implementation of HashMap using Open Addressing (Linear Probing)

// Linear Probing is a collision resolution technique.
// When a collision occurs, we move to the next index
// until an empty slot is found.

// If a key is deleted, the slot is marked with a dummy node
// (key = -1) instead of NULL.
// This ensures that search operations do not stop early
// and can still find keys inserted after a collision.

class Node {
  
  public:
    int key;
    int value;

    Node(int k, int val) : key(k), value(val) {};

};

class Hashmap {

  private:

  // Node** arr is an array where each index stores a pointer to a Node
    Node** arr;
    int cap;
    int size;

    Node* dummy;

  public:

    Hashmap() {
      cap = 10;
      size = 0;
      arr = new Node*[cap];
      for(int i = 0; i < cap; i++) arr[i] = NULL;
      dummy = new Node(-1, -1);
    }

    int hashFunction(int key); 
    bool isEmpty();
    void insertion(int key, int value);
    void deletion(int key);
    int search(int key);
    void display();
   
};

int Hashmap::hashFunction(int key) {
  return key % cap;
}

void Hashmap::insertion(int key, int value) {

  Node* temp = new Node(key, value);
  int hashkey = hashFunction(key);

  while(arr[hashkey] != NULL && arr[hashkey]->key != key && arr[hashkey]->key != -1) {
    hashkey++;
    hashkey %= cap;
  }

  if(arr[hashkey] == NULL || arr[hashkey]->key == -1) {
    size++;
    arr[hashkey] = temp;
  }

}

void Hashmap::deletion(int key) {

  int hashkey = hashFunction(key);
  int keyExist = false;

  while(arr[hashkey] != NULL) {
    if(arr[hashkey]->key == key) {
      keyExist = true;
      delete arr[hashkey];
      arr[hashkey] = dummy;
      size--;
      std::cout << "Value has been deleted.\n";
      break;
    } 
    hashkey++;
    hashkey %= cap;
  }

  if(!keyExist) std::cout << "Value doesn't even Exist :(\n";

  return;

}

int Hashmap::search(int key) {

  int hashkey = hashFunction(key);
  int count = 0;

  while(arr[hashkey] != NULL) {
    if(count++ > cap) break;
    if(arr[hashkey]->key == key) return arr[hashkey]->value;
    hashkey++;
    hashkey %= cap;
  }

  return -1;
}

bool Hashmap::isEmpty() {
  return size == 0;
}

void Hashmap::display() {

  for(int i = 0; i < cap; i++) {
    if(arr[i] != NULL && arr[i]->key != -1) {
      std::cout << "Index: " << i << ", " << "Key: " << arr[i]->key << ", Value: " << arr[i]->value << '\n';
    }
  }

}

int main() {

  Hashmap hm;

  if(hm.isEmpty()) {
    std::cout << "Empty.\n";
  } else {
    std::cout << "Not empty.\n";
  }

  hm.insertion(754, 1);
  hm.insertion(453, 2);
  hm.insertion(527, 3);
  hm.insertion(868, 4);
  hm.insertion(324, 5);

  hm.deletion(527);
  hm.deletion(999);

  hm.display();

  if(hm.isEmpty()) {
    std::cout << "Empty.\n";
  } else {
    std::cout << "Not empty.\n";
  }

  std::cout << hm.search(868) << '\n';
  std::cout << hm.search(440) << '\n';


  return 0;
}