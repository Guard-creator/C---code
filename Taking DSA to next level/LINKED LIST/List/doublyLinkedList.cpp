#include <iostream>

// the other type of linked list is 
// Doubly link list 
// just like singly, each node also have pointer of next value but 
// also a pointer to the previous value
// [NULL][A][52] [45][B][86] [32][C][NULL]
//  |     |   |    |__________                  |
// Head data  next pointer   |        tail
//                         previous pointer

struct Node {
  Node* prev; // point to previous
  int data;
  Node* next; // point to next 
};

int main () {

  Node* first = new Node();
  Node* second = new Node();
  Node* third = new Node();
  Node* forth = new Node();

  first->data = 10;
  second->data = 20;
  third->data = 30;
  forth->data = 40;

  // pointing to the previous and next
  first->prev = NULL;
  first->next = second;
  second->prev = first;
  second->next = third;
  third->prev = second;
  third->next = forth;
  forth->prev = third;
  forth->next = NULL;

  Node* temp = first;
  while(temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }

  std::cout << '\n';

  // reverse because we see through previous pointer
  Node* tempo = forth;
  while(tempo != NULL) {
    std::cout << tempo->data << " ";
    tempo = tempo->prev;
  }


  return 0;
}