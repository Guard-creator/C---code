#include <iostream>

// leetCode number 142
// Cycle in Linked List ||
// Basically it's the same thing but we have to find where the cycle started

// we will first use Flyod Algorithm to check if cycle exist or not 
// then if exist both pointer will eventually land somewhere in 
// the range of cycle 
// means comfirm a cycle is forming 
// then we take the first pointer (fast) 
// and set it to head and the other pointer slow will be at metting point
// then we will take one step from both ptr at a time
// and then it will eventually land to where the cycle start
// Why does this always work?

// Because:
// The guy starting at head (fast) needs exactly L steps to reach the cycle start.
// The guy starting inside the cycle (slow) also needs exactly L steps 
// (he wraps around inside the loop).
// So both land at the cycle start at the same time.

/* READ THIS IF YOU DONT GET MAYBE YOU GET IT HERE

Phase 1 → Collision inside the loop
ptr1 (fast) runs twice as fast as ptr2 (slow).
Once they’re both inside the cycle, fast keeps gaining 1 step per move.
Eventually → fast laps slow → they meet at some node inside the cycle.
That’s the collision point.
(It doesn’t matter where they collide — only that it proves a cycle exists.)

Phase 2 → Reset & Walk Together
Now the trick:
Reset ptr1 back to head.
Keep ptr2 at the collision point.
Now move both 1 step at a time.

Why does this work?
The distance from head to cycle start = L.
The distance from collision point to cycle start (going forward) also = L (modulo cycle length).
So after exactly L steps:
ptr1 (from head) reaches cycle start.
ptr2 (from collision point) also reaches cycle start.
👉 They meet exactly at the cycle’s beginning.
*/

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

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            // if the cycle is found both fast and slow meet at some point
            // then after both are at same Node
            // we will take fast and set it to head
            // then we will take one step 
            // and eventually since slow is stuck at Cycle
            // fast that comes from head 
            // both meet exactly at where the cycle start
            if(fast == slow) {
                fast = head;
            // Move one step at a time
            while(fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
            }

        }

    return NULL;


    }
};

int main() {
    // Example linked list with a cycle
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(4);

    // creating a cycle manually
    head->next->next->next->next = head->next; // cycle starts at node with value 2

    Solution s;
    Node* cycleStart = s.detectCycle(head);

    if (cycleStart)
        std::cout << "Cycle starts at node with value: " << cycleStart->val << '\n';
    else
        std::cout << "No cycle detected.\n";

    return 0;
}
