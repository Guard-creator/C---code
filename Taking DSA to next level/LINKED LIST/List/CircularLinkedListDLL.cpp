#include <iostream>

// right Circular Linked list 
// Doubly linked list
// i explain this in sll so check there(not rocket science bruh)

// i did a little twist...💫
// i will use head as well as tail to implement cdll 
// from previos i only been using head for base but now 
// let's make this more intresting

// first thing 
// now there is head and tail as base 
// insertion and deletion and replace will work differently
// suppose if we choose a pos near tail 
// Do we have to tro tail or head??
// if we go through tail it will be slow 
// so we separate this 
// if the pos is near head 
// it will loop through head to pos (temp->next)
// if the pos is near tail 
// it will loop through tail to pos (temp->prev)

// to find if pos is near head or tail
// we will take it size and half it 
// so if pos is <= size / 2 means it's near head
// if pos > size / 2 means it's near tail

struct Node {

  int data;
  Node* next;
  Node* prev;

  Node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  }

};

class CircularDoublyLinkedList {

  Node* head;
  Node* tail;
  
  public: 

    CircularDoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertionAthead(int val) {

      // insert new node before head and move head to newNode
      Node* newNode = new Node(val);
      if(!head) {
        head = tail = newNode;
        head->prev = head->next = head;
        return;
      }
      newNode->next = head;
      newNode->prev = tail;
      head->prev = newNode;
      tail->next = newNode;
      head = newNode; // move head to newNode

    }

    void insertionAtTail(int val) {

      // insert new node after tail and move tail to newNode
      Node* newNode = new Node(val);

      if(!tail) {
        head = tail = newNode;
        head->prev = head->next = head;
        return;
      }
      newNode->next = head;
      newNode->prev = tail;
      head->prev = newNode;
      tail->next = newNode;
      tail = newNode; // move tail to newNode

    }

    void insertionAtSpecificPlace(int pos, int val) {
      // insert at any pos -> check head side or tail side traversal
      Node* newNode = new Node(val);
      if(!head) {
        head = tail = newNode;
        head->next = head->prev = head;
        return;
      }
      
      if(pos == 1) { // special case head
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
        return;
      }

      Node* count = head;
      int size = 0;
      do {
        count = count->next;
        size++;
      } while(count != head);

      if(pos < 1 || pos > size + 1) {
        std::cout << "Out of Range.\n";
        return;
      }

      if(pos == size + 1) { // special case tail
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
        return;
      }

      if(pos <= size / 2) {

        // go from head forward
        Node* temp = head;
        for(int i = 1; i < pos - 1; i++) {
          temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

      } else if (pos > size / 2) {
        
        // go from tail backward
        Node* temp = tail;
        int step = size - pos + 1;
        for(int i = 1; i < step; i++) {
          temp = temp->prev;
        }
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;

        // another thing we can do here 
        // is to go before the element we are inserting(at loop(i = 0))
        // but this could causae problem
        // forward Approach
        // newNode->next = temp->next;
        // newNode->prev = temp;
        // temp->next->prev = newNode;
        // temp->next = newNode;
        // we just take the loop and gon step back from the element that aare inserting there
        // and change there next and prev 
        // both implementation is good 

      }

    }

    void deleteAtHead() {

      // just delete the head and move it forward
      if(!head) return; 
      if(head->next == head) { delete head; head = tail = NULL; return; };
      Node* temp = head;
      head = head->next;
      head->prev = tail;
      tail->next = head;
      delete temp;

    }

    void deleteAtTail() {

      // just delete the tail and move it backward
      if(!head) return;
      if(head->next == head) { delete head; head = tail = NULL; return; }
      Node* temp = tail;
      tail = tail->prev;
      head->prev = tail;
      tail->next = head;
      delete temp;

    }

    void deleteAtSpecificPlace(int pos) {
      // delete from any pos -> check head side or tail side traversal
      if(!head) return;
      if(pos == 1) { // special case head
        if(head->next == head) { delete head; head = tail = NULL; return; }
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
        return;
      }

      Node* count = head;
      int size = 0;
      do {
        count = count->next;
        size++;
      } while(count != head);

      if(pos < 1 || pos > size) {
        std::cout << "Out of Range.\n";
        return;
      }

      if(pos == size) { // special case tail

        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        return;

      }

      if(pos <= size / 2) {

        // go from head forward
        Node* temp = head;

        for(int i = 1; i < pos; i++) {
          temp = temp->next;
        }

        Node* toDelete = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete toDelete;

      } else if(pos > size / 2) {

        // go from tail backward
        int step = size - pos + 1;
        Node* temp = tail;

        for(int i = 1; i < step; i++) {
          temp = temp->prev;
        }

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;

      }
    }

    void replaceWith(int pos, int val) {

      // replace data at pos (traverse from head or tail)
      if(!head) return;
      if(pos == 1) {head->data = val; return;}

      Node* count = head;
      int size = 0;
      do {
        count = count->next;
        size++;
      } while(count != head);

      if(pos < 1 || pos > size) {
        std::cout << "Out Of Range.\n";
        return;
      }

      if(pos <= size / 2) {

        // go from head forward
        Node* temp = head;
        for(int i = 1; i < pos; i++) {
          temp = temp->next;
        }

        temp->data = val;

      } else if(pos > size / 2) {

        // go from tail backward
        int step = size - pos + 1;
        Node* temp = tail;

        for(int i = 1; i < step; i++) {
          temp = temp->prev;
        }

        temp->data = val;

      }
    }

    int count() {

      if(!head) return  0;

      Node* temp = head;
      int count = 0;

      do {
        temp = temp->next;
        count++;
      } while(temp != head);

      return count;

    }

    void display() {

      if(!head) return;

      Node* temp = head;
      std::cout << "tail";
      do {
        std::cout << " <- " << temp->data << " -> ";
        temp = temp->next;
      } while(temp != head);
      std::cout << "head";

    } 

};

int main() {
  CircularDoublyLinkedList list;

  std::cout << "After Insertion: ";
  list.insertionAthead(1);
  list.insertionAthead(2);
  list.insertionAtTail(3);
  list.insertionAtTail(4);
  list.insertionAtSpecificPlace(3, 65);
  list.display();

  std::cout << '\n';

  std::cout << "After Deletion: ";
  list.insertionAthead(42);
  list.insertionAthead(54);
  list.insertionAthead(76);

  list.deleteAtHead();
  list.deleteAtTail();
  list.deleteAtSpecificPlace(4);
  list.replaceWith(5, 69);
  list.display();
  std::cout << '\n' << "Count: " << list.count() << '\n';

  return 0;
}
