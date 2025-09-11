#include <iostream>

// Definition for singly-linked list.

        // --- Method 1: Count length ---
        // Step 1: Count the total number of nodes
        // Step 2: Find the (length - n)th node
        // Step 3: Adjust links to skip the nth node from the end
        

        // --- Method 2: Two pointers ---
        // Step 1: Create two pointers (fast and slow)
        // Step 2: Move fast ahead by n steps
        // Step 3: Move both fast and slow together until fast reaches the end
        // Step 4: Now slow is just before the node to delete
        // Step 5: Adjust links to remove that node

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

      ListNode* temp = head;
      int count = 0;
      
      while(temp != NULL) {
        temp = temp->next;
        count++;
      }

      int step = (count - n);

      ListNode* temp2 = head;
      for(int i = 0; i < step - 1; i++) {
        temp2 = temp2->next;
      }

      ListNode* toDelete = temp2->next;
      temp->next = temp->next->next;
      delete toDelete;

      temp2 = head;
      return temp2;

    }
};

int main() {
    // Example test case setup
    // Build linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int n = 2; // remove 2nd node from end
    ListNode* result = sol.removeNthFromEnd(head, n);

    // Print updated list
    while (result != NULL) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
