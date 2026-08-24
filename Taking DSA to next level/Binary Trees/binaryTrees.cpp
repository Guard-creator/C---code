#include <iostream>
#include <vector>

// A BINARY TREE
// is a data struture where each node connect to one another like an tree with roots and leaf
// each node an have maximum of two child nodes an left one and right one.
// we use binary tree to achieve an efficient balance of fast search, insertion, 
// and deletion operations while maintaining data in a structured, hierarchical, or sorted order. 

// we dont usually implement this data struture because 
// the node can be plcaed in anyway..

// structure of tree  
//     10
//    /  \
//   5    20
//  / \     \
// 3   7     30

struct Node {

  int data;
  Node* left;
  Node* right;

    Node(int val) {
      data = val;
      left = right = NULL;
    }

};

static int idx = -1;
Node* build(std::vector<int> vec) {

  idx++;

  if(vec[idx] == -1) return NULL;

  Node* root = new Node(vec[idx]);
  root->left = build(vec);
  root->right = build(vec);

  return root;

}

int main() {

  std::vector<int> let = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node* root = build(let);
  std::cout << "Root: " << root->data << '\n';
  std::cout << "left: " << root->left->data << '\n';
  std::cout << "right: " << root->right->data << '\n';

  return 0;
}