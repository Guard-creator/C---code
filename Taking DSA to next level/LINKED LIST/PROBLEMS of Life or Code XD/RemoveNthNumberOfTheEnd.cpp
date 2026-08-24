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
    ListNode* removeNthFromEndCount(ListNode* head, int n) {

      ListNode* temp = head;
      // getting length
      int length = 0;

      while(temp != NULL) {
        temp = temp->next;
        length++;
      }

      // we are deleting from the en
      // so if length == n (means at the head)
      // we simply del the head
      if(length == n) {
        return head->next;
      }

      // go to the nth Node
      temp = head;
      for(int i = 1; i < length - n; i++) {
        temp = temp->next;
      }

      // remove it
      temp->next = temp->next->next;

      return head;

    }

    ListNode* removeNthFromEndTwoPointer(ListNode* head, int n) {

      // the dummy acts like a base node before the head, which makes it 
      // possible to delete the head using the same logic as deleting any other node.
      ListNode* dummy = new ListNode(0);
      dummy->next = head;

      ListNode* fast = dummy;
      ListNode* slow = dummy;

      // fast will go to exactly at Nth Node
      for(int i = 0; i <= n; i++) {
        fast = fast->next;
      }

      // then both take one step ahead
      // fast will reach the NULL first 
      // because there is nth Node difference 
      // fast is already at nth node 
      // and by the time fast reach the NULL
      // slow will be at Nth Node
      // Both are taking one step 
      // that's why the difference remain
      while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
      }

      // the nsimply jsut remove it
      slow->next = slow->next->next;

      // return dummy
      return dummy->next;

    }

  
};

int main() {
    // Example test case setup
    // Build linked list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    // Test Method 1
    ListNode* result1 = sol.removeNthFromEndCount(head, 2);
    std::cout << "Method 1 (Count length): ";
    while (result1 != NULL) {
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << '\n';

    // Build list again for Method 2 (since previous one got modified)
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Test Method 2
    ListNode* result2 = sol.removeNthFromEndTwoPointer(head, 2);
    std::cout << "Method 2 (Two pointers): ";
    while (result2 != NULL) {
        std::cout << result2->val << " ";
        result2 = result2->next;
    }
    std::cout << '\n';

    return 0;
}

