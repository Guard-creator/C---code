#include <iostream>

// LeetCode 876 — Middle of the Linked List
// Problem:
// You are given the head of a singly linked list, and you need to return the middle node.
// - If the number of nodes is odd → return the single middle node.
// - If the number of nodes is even → return the second middle node.
//
// Example:
// Input: 1 → 2 → 3 → 4 → 5
// Output: 3 → 4 → 5 (middle is node 3)
//
// Input: 1 → 2 → 3 → 4 → 5 → 6
// Output: 4 → 5 → 6 (middle is node 4, the second middle)
//
// Note: You don’t return just the value; you return the node itself, 
// meaning the whole linked list starting from the middle.

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //  Method 1: Count length of list
    //  Traverse the list once to count total nodes
    //  Calculate half (count / 2)
    //  Traverse again up to that index and return the node
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        // Count the total nodes
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }

        // Move to middle index
        ListNode* found = head;
        for (int i = 0; i < count / 2; i++) {
            found = found->next;
        }

        return found;
    }

    //  Method 2: Fast & Slow pointer (Floyd’s algorithm idea)
    //  Fast moves 2 steps at a time, slow moves 1 step
    //  When fast reaches end, slow will be at the middle
    //  Automatically gives the correct "second middle" in even case
    ListNode* middleNodeIn(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution sol;

    // Method 2 (Fast & Slow pointer)
    ListNode* mid1 = sol.middleNodeIn(head);
    std::cout << "Method 1 (Fast & Slow pointer): ";
    while (mid1 != NULL) {
        std::cout << mid1->val << " ";
        mid1 = mid1->next;
    }
    std::cout << '\n';

    // Method 1 (Count length)
    ListNode* mid2 = sol.middleNode(head);
    std::cout << "Method 2 (Count length): ";
    while (mid2 != NULL) {
        std::cout << mid2->val << " ";
        mid2 = mid2->next;
    }

    return 0;
}
