#include <bits/stdc++.h>

using namespace std;

// LeetCode 950: Reveal Cards in Increasing Order

// You’re given a deck of unique integers.
// You can perform this operation repeatedly:
// 1 Take the top card and place it on the table (revealed).
// 2 Take the next top card and place it at the bottom of the deck.
// 3 Repeat until all cards are revealed.
// Your goal:
// Return the initial order of the deck such that when you perform the process,
// the cards are revealed in increasing order.

// Example: 
// Input:
// deck = [17, 13, 11, 2, 3, 5, 7]
// Output:
// result = [2, 13, 3, 11, 5, 17, 7]
// When we perform the Operations Repeatedly 
// we get the Increasing Order 

// Solution
// if we are arranging the deck in Increasing Order
// when Operations Happen
// Means we need to sort the deck first before going to Operation
// We will use queue but we can also use Queue
// we need only the front and follow the FIFO (Queue Only Store Index of Deck)
// Now Implementing The Operations
// We will take the front(as index) of Queue then pop it
// then store the Element in result using the queue front of Queue (As Queue is Sorted)
// Then we check if Not Empty then
// Push the front Queue in Queue
// then pop it 
// this way we follow all the Operations until the deck Runs out of cards
// Not Understand Yet?
//...
//...
//...
// Suppose Queue is the Deck of Card 
// We will take The First Card of the Deck and store that in Result 
// then take the Next first Deck of Card and put it in Bottom 
// we will repeat this until all the Cards Runs Out 
// if you look at the Queue 
// this is how the Queue will look like
// qu = [0, 1, 2, 3, 4, 5, 6]
// qu = [2, 3, 4, 5, 6, 1]
// qu = [4, 5, 6, 1, 3]
// qu = [6, 1, 3, 5]
// qu = [3, 5, 1]
// qu = [1, 5]
// qu = [5]
// qu = [] Card Runs Out

class Solution {
  public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {

    int n = deck.size();
    queue<int> qu;
    vector<int> result(n);

    sort(deck.begin(), deck.end());

    for(int i = 0; i < n; i++) {
      qu.push(i);
    }

    for(int i = 0; i < n; i++) {
      int indx = qu.front();
      qu.pop();
      result[indx] = deck[i];
      if(!qu.empty()) {
        qu.push(qu.front());
        qu.pop();
      }
    } 

    return result;
  }
};

int main() {

  Solution sol;

  vector<int> deck = {17,13,11,2,3,5,7};
  vector<int> res = sol.deckRevealedIncreasing(deck);

  std::cout << "Deck: ";
  for(int card : res) {
    std::cout << card << " ";
  }

  return 0;
}