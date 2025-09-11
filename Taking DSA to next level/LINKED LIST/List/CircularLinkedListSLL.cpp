#include <iostream>

// Circular Linked List 
// sound exactly as the name says 
// here Head and tails are connect to eachother not all CLL

// IN Circular Singly Linked List
// only tails is connected to the head like this
// head → [10] → [20] → [30] → back to head

// In Circular Doubly Linked List
// tails and head are both connect to each other
// back to tails ↔ [10] ↔ [20] ↔ [30] ↔ back to head
//                  |              |
//                 head           tails

// we will implement Circular Singly Linked List here LET"S GO

struct Node {
  int data;
  Node* next; 
    Node(int val) {
      data = val;
      next = NULL;
    }
};

class CircularSinglyLinkedList {

  Node* head;

  public:

    CircularSinglyLinkedList() : head(NULL) {}

    void insertionAtHead(int val) {

      Node* newNode = new Node(val);
      // check if head is empty or not
      if(!head) {
        newNode->next = newNode; // point to it's self
        head = newNode;
        return;
      }

      // first we will go to the tail
      // so we change tail next to point to new head
      Node* temp = head;
      while(temp->next != head) {
        temp = temp->next;
      }

      temp->next = newNode;
      newNode->next = head;
      head = newNode;

    }

    void insertAtTail(int val) {

      Node* newNode = new Node(val);
      // same if head is empty
      if(!head) {
        newNode->next = newNode; // point itself
        head = newNode;
        return;
      }
      // going to the tail
      // to insert new tail
      Node* temp = head;
      while(temp->next != head) {
        temp = temp->next;
      }
      newNode->next = head; // new tail will point back to head
      temp->next = newNode; // old tail will now point to new node

    }

    void insertAtSpecficPlace(int pos, int val) {
      
      Node* newNode = new Node(val);
      // if empty return
      if(!head) return;
      // if pos is 1 then simply add to head
      if(pos == 1) {
        Node* temp = head;
        while(temp->next != head) {
          temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
      }

      // if it's out of range then dont go any farther
      Node* temp = head;

      int size = 0;
      Node* count = head;
      do {
        count = count->next;
        size++;
      } while(count != head);

      if(pos < 1 || pos > size + 1) {
        std::cout << "Out of Range.\n";
        return;
      }

      // move temp to the node before insertion point
      for(int i = 1; i < pos - 1; i++) {
        temp = temp->next;
      }

      // insert node between temp and temp->next
      newNode->next = temp->next;
      temp->next = newNode;

    }

    void deleteAtHead() {
      
      if(!head) return; // if empty
      if(!head->next) { delete head; head = NULL; return; } // if only head exist
      // go to the tail
      Node* temp = head;
      while(temp->next != head) {
        temp = temp->next;
      }
      Node* toDelete = head; // save it to del
      head = head->next;     // move head forward
      temp->next = head; // then point the tail to the head 
      delete toDelete;   // delete old head

    }

    void deleteAtTail() {

      if(!head) return;
      if(!head->next) { delete head; head = NULL; return; }
      Node* temp = head;
      // go to the second element of last tail
      while(temp->next->next != head) {
        temp = temp->next;
      }
      Node* toDelete = temp->next; // store tail
      temp->next = head;           // new tail points to head
      delete toDelete;

    }

    void deleteAtSpecificPlace(int pos) {
      
      if(!head) return; 
      if(pos == 1) { // if pos is 1 then simply delete head
        Node* temp = head;
        // if there is single element delete that
        if(head->next == head) { delete head; head = NULL; return; }
        while(temp->next != head) {
          temp = temp->next;
        }
        Node* toDelete = head;
        head = head->next;   // move head forward
        temp->next = head;   // tail points to new head
        delete toDelete;
        return;
      }

      Node* temp = head;

      // check length 
      // to check if the pos is invalid 
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

      // move temp to node before position
      for(int i = 1; i < pos - 1; i++) {
        temp = temp->next;
      }

      // our tail can also be handle this way
      Node* toDelete = temp->next; // store the element to del
      temp->next = temp->next->next; // then point to next element of element that we want to del
      delete toDelete;

    }

    void replaceWith(int pos, int val) {

      if(!head) return;
      if(pos == 1) { head->data = val; return; }

      // first count total nodes
      Node* count = head;
      int size = 0;
      do{
        count = count->next;
        size++;
      } while(count != head);

      // validate position
      if(pos < 1 || pos > size) {
        std::cout << "Out of Range.\n";
        return;
      }

      // move to target node
      Node* temp = head;
      for(int i = 1; i < pos; i++) {
        temp = temp->next;
      }

      temp->data = val; // replace data

    }

    int count() {

      if(!head) return 0;

      Node* temp = head;
      int size = 0;
      do {
        temp = temp->next;
        size++;
      } while(temp != head);

      return size;
    }

    void display() {

      if(!head) return;

      Node* temp = head;
      do {
        std::cout << temp->data << " -> ";
        temp = temp->next;
      } while(temp != head);
      std::cout << "head";

    }

};



int main() {

  CircularSinglyLinkedList list;

  std::cout << "After Inserting: ";

  list.insertionAtHead(5);
  list.insertAtTail(3);
  list.insertAtSpecficPlace(2, 2);
  list.insertAtSpecficPlace(2, 65);
  list.insertAtSpecficPlace(1, 4);

  list.display();
  std::cout << '\n';

  std::cout << "After Deletion: ";

  list.deleteAtHead();
  list.deleteAtTail();
  list.deleteAtSpecificPlace(1);

  list.display();

  std::cout << '\n';

  std::cout << "After Some Unknown Function: ";

  list.insertionAtHead(32);
  list.insertAtTail(23);

  list.replaceWith(2, 43);

  list.display();
  std::cout << '\n';
  std::cout << "Count: " << list.count() << '\n';

  return 0;  
}
