#include <iostream>

// WHY ARE WE TALKING ABOUT LINKED LIST IN DSA WHEN WE ALREADY KNOW WHAT IS LINKED LIST IN STL ?????
// that was the question i was asking myself after some study 
// linked list are used in most problem and dsa and are lot of problem to solve them using linkedlist 
// we will implement it's function and the other two types of linked list

// FIRST let's clarify what is linked list 
// linked list are sed to store linear types of data
// that are connect to each other like in train section
// this can be used in music playlist or GPS navigation

// there are two types of linked list 
// first is Singly Linked list
// in this list each value is pair with it next value memory or where it locates
// like this 
// || [23][Xg4t4] -> [13][fxrjk2] -> [56][NULL] || <--Last value doesn't point to anywhere tho is NULL
//  |     |
// Data  Pointer to the Next Value

// Another thing Linked list used alot of memory because of the pointer of next value
// Good for insert/delete (O(1) if you have the pointer).

// WHY IT GOOD IN INSERT/DELETE
// ARRAY CAN ALSO DO THE SAME 
// nah bruh
// Array have a major issue when it comes to insert delete
// when we insert a value in middle(or Anywhere) in Array 
// we have to shift the values of other after the next value we are inserting like this
// [1][0] [2][1] [3][2] [i][i] [4][3] [5][4] [6][5]
//                        |
//                     Inserting here
// so at index 3 4 and 5 have to shift because a value is inserting
// this is not a issue is small arrays
// but imagine working with 1 MILLION values
// will be slow huh dwag..
// in linked list
// head → [10] → [20] → [30] → NULL
// we will insert 15 between 10 and 20
// - first we will create a new node with 15 in it
// - then in the new node we will point to the 20 becasue when we insert 15 it 
//   should point to the next value which is 20
// - after that we will change 10 so that it will point to the next new node 15
// VISUAL
// head → [10] → [15] → [20] → [30] → NULL
// Only 2 pointer changes needed → O(1) operation (if you already have the pointer to position).

// well that's Everything about linked list
// and down below is the implementation of Singly linked list

// we sue struct for implementation
struct Node {
  int data;
  Node* next; // point to the next node
};
 
int main() {

  // create there nodes
  Node* first = new Node();
  Node* second = new Node();
  Node* third = new Node();

  // store values in it
  first->data = 10;
  second->data = 20;
  third->data = 30;

  // then point to it's next nodes
  first->next = second;
  second->next = third;
  third->next = NULL;

  // then simply display it
  Node* temp = first;
  while(temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }

}