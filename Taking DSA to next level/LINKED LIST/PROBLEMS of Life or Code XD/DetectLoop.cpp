#include <iostream>

// LeetCode 141  Detect a Loop (Cycle in Linked List)
// We’re given a linked list.
// Normally, the last node points to NULL, meaning the list ends.
// But sometimes, due to a wrong connection, a node’s next pointer may 
// point back to a previous node → this creates a loop (cycle).

// Check if the linked list has a loop or not.
// If yes → return true (or print "Loop found").
// If no → return false (or print "No loop").

// List: 1 → 2 → 3 → 4 → 5 → NULL → No loop.

// List: 1 → 2 → 3 → 4 → 5 —————|
//           |——————— (points back to node 2) → Loop exists.

// TO SOLVE THIS 
// there is an algorithm Called Flyod Detection loop 
// it works for linked list problem like this 
// Use two pointers:
// slow → moves 1 step each time
// fast → moves 2 steps each time
// Case 1: No loop → fast eventually hits NULL → no cycle.
// Case 2: Loop exists → since both are inside a finite loop, 
// fast keeps closing the gap by 1 step each move → they will definitely 
// meet at some node inside the cycle.
// this is mathatically not random chance 


struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to detect loop in linked list
bool detectLoop(Node* head) {
    Node* fast = head;
    Node* slow = head;

    // But before we move fast, we must make sure:
    // fast itself is not NULL
    // fast->next is not NULL
    // otherwise program can crash

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next; // two  steps 
        slow = slow->next; // one step

        // if same Node is found then 
        // it's a Cycle we going around
        if(fast == slow) {
            return true;
        }
    }

    return false;
}

int main() {
    // Create nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Manually create a loop for testing
    head->next->next->next->next->next = head->next; // 5 -> 2

    if (detectLoop(head))
        std::cout << "Loop found!" << '\n';
    else
        std::cout << "No loop." << '\n';

    return 0;
}
