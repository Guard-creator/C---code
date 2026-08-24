#include <iostream>
#include <vector>

// A Binary Search Tree is a Binary Tree where every node's left child has a 
// lower value, and every node's right child has a higher value.

// A clear advantage with Binary Search Trees is that operations like search,
//  delete, and insert are fast and done without having to shift values in memory.

// The X node's left child and all of its descendants (children, children's children,
// and so on) have lower values than X's value.
// The right child, and all its descendants have higher values than X's value.
// Left and right subtrees must also be Binary Search Trees.

// to check if a Binary Tree is BST, is to do an in-order traversal 
// (like we did on the previous page) and check if the resulting list 
// of values are in an increasing order.



class Node {

  public:

  int data;
  Node* left;
  Node* right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}

};

class BST {

  Node* root;

  Node* insertHelper(Node* node, int val) { 

    if(!node) return new Node(val);
    if(val < node->data) {
      node->left = insertHelper(node->left, val);
    } else if(val > node->data) {
      node->right = insertHelper(node->right, val);
    }
    return node;

  }

  bool searchHelper(Node* node, int val) {

    if(!node) return false;
    if(node->data == val) return true;
    if(val < node->data) {
      searchHelper(node->left, val);
    } 
    return searchHelper(node->right, val);

  }


  void displayHelper(Node* node) {

    if(!node) return;
    displayHelper(node->left);
    std::cout << node->data << " ";
    displayHelper(node->right);

  }

  public:

  BST() {
    root = nullptr;
  }

  void insert(int val) {
    root = insertHelper(root, val);
  }

  bool search(int val) {
    return searchHelper(root, val);
  }

  void display() {
    std::cout << "BST: \n";
    displayHelper(root);
    std::cout << "\n\n";
  }


};



int main() {

  BST tree; 

  tree.insert(2);
    tree.insert(1);
      tree.insert(5);
        tree.insert(6);
          tree.insert(7);
            tree.insert(8);
              tree.insert(3);
                tree.insert(4);


  tree.display();
  

  std::cout << (tree.search(9) ? "Yes Exist" : "Not Exist");
  std::cout << "\n";
  std::cout << (tree.search(8) ? "Yes Exist" : "NoT exist");


  return 0;
}