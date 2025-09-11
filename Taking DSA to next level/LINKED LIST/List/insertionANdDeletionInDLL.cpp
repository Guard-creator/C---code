#include <iostream>

// now we will implement doubly linked list funtion all 
// this is quite easy just have to make sure when we insert a node a
// prev we should check it's head 
// that it's or not otherwise it would be waster

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

class DoublyLinkedList {

  Node* head;

  public:

    DoublyLinkedList() : head(NULL) {};

    void insertionAtHead(int val) {

      Node* newNode = new Node(val);
      newNode->next = head;
      if(head) head->prev = newNode;
      head = newNode;

    }

    void insertionAtTails(int val) {

      Node* newNode = new Node(val);
      if(!head) { head = newNode; return; }
      Node* temp = head;
      while(temp->next) temp = temp->next;
      temp->next = newNode;
      newNode->prev = temp;

    }

    void insertionAtSpecificPlace(int pos, int val) {

      Node* newNode = new Node(val);

      if(pos == 1) {
        newNode->next = head;
        if(head) head->prev = newNode;
        head = newNode;
        return;
      }

      Node* temp = head;
      for(int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
      }
      
      if(!temp) {
        std::cout << "Out of Range\n";
        delete newNode;
        return;
      }

      newNode->next = temp->next;
      newNode->prev = temp;
      if(temp->next) temp->next->prev = newNode;
      temp->next = newNode;
    }

    void deleteAtHead() {

      if(!head) return;
      Node* temp = head;
      head = head->next;
      if(head) head->prev = NULL;
      delete temp;

    }

    void deleteAtTails() {

      if(!head) return;

      if(!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while(temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
      }

    void deleteAtSpecificPlace(int pos) {

      if(!head) return;

      if(pos == 1) {
        Node* temp = head;
        head = head->next;
        if(head) head->prev = NULL;
        delete temp;
        return;
      }

      Node* temp = head;
      for(int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
      }

      if(!temp || !temp->next) {
        std::cout << "Out of Range.\n";
        return;
      }

      Node* toDelete = temp->next;
      temp->next = temp->next->next;
      if(temp->next) temp->next->prev = temp;
      delete toDelete;

    }

    void replaceWith(int pos, int val) {

      Node* temp = head;

      if(pos == 1) {
        head->data = val;
        return;
      }

      for(int i = 1; temp && i < pos; i++) {
        temp = temp->next;
      }

      if(!temp) {
        std::cout << "Out of Range.\n";
        return;
      }

      temp->data = val;
    }

    int count() {

      int count = 0;
      Node* temp = head;

      while(temp) {
        count++;
        temp = temp->next;
      }

      return count;
    }

    void display() {

      Node* temp = head;

      std::cout << "NULL";
        while(temp) {
          std::cout << " <- " << temp->data << " -> ";
          temp = temp->next;
        }
      std::cout << "NULL" << '\n';

    } 

    void displayReverse() {

      Node* temp = head;

      while(temp->next) {
        temp = temp->next;
      }

      std::cout << "NULL";
      while(temp) {
        std::cout << " <- " << temp->data << " -> ";
        temp = temp->prev;
      }
      std::cout << "NULL" << '\n';

    }
 
};


int main() {

  DoublyLinkedList list;

  list.insertionAtHead(10);
  list.insertionAtHead(20);
  list.insertionAtTails(30);
  list.insertionAtTails(40);

  list.insertionAtSpecificPlace(5, 69);

  std::cout << "Insertion Method: ";
  list.display();

  
  list.deleteAtHead();
  list.deleteAtTails();
  list.deleteAtSpecificPlace(3);
  list.insertionAtTails(40);
  list.replaceWith(2, 65);

  std::cout << "Deletion Method: ";
  std::cout << "Count: " << list.count() << '\n';
  list.display();
  std::cout << "Reverse: ";
  list.displayReverse();

  return 0;
}