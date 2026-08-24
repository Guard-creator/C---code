#include <iostream>

// LeetCode 21 — Merge Two Sorted Lists
// Problem: Merge two sorted linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes of the first two lists.

// Example:
// list1 = 1 → 2 → 4
// list2 = 1 → 3 → 4
// Output: 1 → 1 → 2 → 3 → 4 → 4

    // --- Method 1: Iterative with Dummy Node ---
    // Steps:
    // 1. Create a dummy node and a "tail" pointer.
    // 2. Compare list1 and list2, pick the smaller node, attach it to tail.
    // 3. Move forward in the list you picked from.
    // 4. Continue until one list is exhausted.
    // 5. Attach the remaining nodes.
    // 6. Return dummy->next.

    // --- Method 2: Recursive ---
    // Steps:
    // 1. If one list is NULL, return the other list.
    // 2. Compare list1->val and list2->val.
    // 3. Attach the smaller one to the result and recurse for the rest.
    // 4. Return the node you attached.

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {

      // dummy node help to handle the head
      // it's like starting point of the mergeSort
      // then tail will help to attach to those list
      ListNode* dummy = new ListNode(0);
      ListNode* tail = dummy;

      // loop will run until if one list is empty
      while(list1 != NULL && list2 != NULL) {
        if(list1->val < list2->val) {
          tail->next = list1; // attach the node
          list1 = list1->next; // move to next
        } else {
          tail->next = list2;
          list2 = list2->next;
        }
        tail = tail->next; // move the tail to next 
      }

      // if one list is empty 
      // means other list still have Node
      // we check if either list does have 
      // we simply attach to the tail
      if(list1 != NULL) {
        tail->next = list1;
      } else if(list2 != NULL) {
        tail->next = list2;
      }

      return dummy->next;
    }

    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        
      // base Case for recursion
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

      // we check both condition if less or greater in list
      // we build the list one by one 
      // suppose if 1, 2, 4, | 1, 3, 4
      // if 1 >= 1 then we keep 1 
      // then after that we do recursion 
      // to find the rest of the value after the ->next
      // like merge(1,2,4 | 3, 4)
      // then recursion slowly build the all the remaining Node in
      // sorted order
        if(list1->val < list2->val) {
           // find the ramaining Sorted Nodes then put it back is list
          list1->next = mergeTwoListsIterative(list1->next, list2);
          return list1; // then return it 
        } else if(list1->val >= list2->val) {
          list2->next = mergeTwoListsIterative(list1, list2->next);
          return list2;
        }
    }
};

int main() {
    // Example test case setup
    // list1 = 1 → 2 → 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // list2 = 1 → 3 → 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;

    // Test Iterative Method
    ListNode* merged1 = sol.mergeTwoListsIterative(list1, list2);
    std::cout << "Iterative: ";
    while (merged1 != NULL) {
        std::cout << merged1->val << " ";
        merged1 = merged1->next;
    }
    std::cout << "\n";

    // Rebuild lists for recursive test
    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Test Recursive Method
    ListNode* merged2 = sol.mergeTwoListsRecursive(list1, list2);
    std::cout << "Recursive: ";
    while (merged2 != NULL) {
        std::cout << merged2->val << " ";
        merged2 = merged2->next;
    }
    std::cout << "\n";

    return 0;
}
