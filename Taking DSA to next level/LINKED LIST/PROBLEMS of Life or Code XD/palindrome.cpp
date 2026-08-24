#include <iostream>
#include <vector>

// LeetCode 234 — Palindrome Linked List
// Problem: Given the head of a singly linked list, return true if it is a palindrome.
// A palindrome means the sequence of values reads the same forward and backward.
//
// Example:
// Input: head = [1,2,2,1]
// Output: true
//
// Input: head = [1,2]
// Output: false
//
// Goal: Check if the linked list is palindrome.
//
// --- Method 1: Copy to Array ---
// Idea:
// 1. Traverse the list and store values in an array.
// 2. Use two pointers (left, right) to check if array is palindrome.
//
// --- Method 2: Reverse Second Half (Optimal O(1) space) ---
// Idea:
// 1. Find middle using slow/fast pointer.
// 2. Reverse the second half of the list.
// 3. Compare first half with reversed second half.
// 4. (Optional) Restore list to original.

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    bool isPalindromeArray(ListNode* head) {

      // storing Nodes in vector 
      std::vector<int> arr;
      ListNode* temp = head;
      while(temp != NULL) {
        arr.push_back(temp->val);
        temp = temp->next;
      }

      // indexes from both side of vec
      int left = 0;
      int right = arr.size() - 1;

      // then compare from left to right 
      // if it doesn't match then it's not palindrome
      // if match loop will end and return true;
      while(left < right) {
        if(arr[left] != arr[right]) {
          return false;
        }
        left++;
        right--;
      } 

        return true;
    }

    bool isPalindromeReverse(ListNode* head) {

      // we get the middle part of the list
      ListNode* fast = head;
      ListNode* slow = head;

      while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
      }

      // reverse the list after middle 
      /*
        nextNode will save the next node, so we don’t lose the rest of the list.
        curr->next = prev : set previous Node that was reverse and put it after the Curr->next
        so this way a newNode added in list in reverse
        then make that current and make it prev (prev = curr)
        so we can still have the reverse part for the next Node
        then simply move the curr to next
      */
      ListNode* prev = NULL;
      ListNode* curr = slow;
      while(curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
      }

      // then compare
      // from mid(that is reverse) and head
      ListNode* first = head;
      ListNode* second = prev;
      while(first != NULL && second != NULL) {
        if(first->val != second->val) {
          return false;
        }
        first = first->next;
        second = second->next;
      }

      return true;
    }

};

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;

    std::cout << "Method 1 (Array): " 
         << (sol.isPalindromeArray(head) ? "true" : "false") << '\n';

    std::cout << "Method 2 (Reverse second half): " 
         << (sol.isPalindromeReverse(head) ? "true" : "false") << '\n';

    return 0;
    
}
