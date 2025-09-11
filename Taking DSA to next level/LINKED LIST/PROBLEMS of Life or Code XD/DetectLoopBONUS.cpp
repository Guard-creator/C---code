#include <iostream>

// this is an Bonus 
// after 141 142 leetcode problem 
// we can get the probllem and detect where the cycle start 
// but how do we end the cycle 
// simply where the cycle start 
// loop around until you see the same node again where 
// the cycle start 
// means after this stop and dont go any farther 
// and take that point to set it NULL

// NOTE THIS
// If a cycle is made in the middle, all nodes after the cycle entry are 
// lost unless you link them inside the cycle.
// Removing the cycle doesn’t “cut them off” — they were already cut 
// off at cycle creation.

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    Node* detectCycle(Node* head) {
        Node* fast = head;
        Node* slow = head;

        // Phase 1: Detect if a cycle exists using Floyd’s algorithm
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; // fast moves 2 steps
            slow = slow->next;       // slow moves 1 step

            if (fast == slow) { 
                // Phase 2: Find the cycle starting point
                // Reset fast to head, move both 1 step at a time
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                // Both pointers now point to the start of the cycle
                return slow;
            }
        }
        return NULL; // No cycle found
    }
};

// Remove the loop if it exists
void removeLoop(Node* head) {
    Solution s;
    Node* startNode = s.detectCycle(head); // find the cycle here
    if (!startNode) {
        std::cout << "No cycle detected. Nothing to remove.\n";
        return;
    }

    // Traverse inside the cycle until the node points back to startNode
    // This gives us the "last" node in the cycle
    Node* ptr = startNode;
    while (ptr->next != startNode) {
        ptr = ptr->next;
    }

    // Break the cycle: the "last" node now points to NULL
    ptr->next = NULL;

    std::cout << "Loop removed. Cycle was starting at value: " 
              << startNode->val << "\n";
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main() {
    // Example: 3 -> 2 -> 0 -> 4
    // And then 4 -> points back to 2 (cycle starts at node 2)
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(4);

    // creating a cycle manually
    head->next->next->next->next = head->next; // cycle starts at node with value 2

    removeLoop(head); // detect & remove the cycle

    std::cout << "List after removing loop: ";
    printList(head); // should print a normal list without cycle

    return 0;
}
