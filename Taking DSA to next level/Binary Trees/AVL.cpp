#include <iostream>

struct Node {

  int data;
  int height;
  Node* left;
  Node* right;

  Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {} 

};

class AVL {

  Node* root;

  int height(Node* node) {
    return node->height;
  }

  int BalanceFactor(Node* node) {
    return height(node->left) - height(node->left);
  }

  
  void updateHeight(Node* node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
  }

  Node* insertHelper(Node* node, int val) {

    if(!node) return new Node(val);
    if(val < node->data) {
      insertHelper(node->left, val);
    } else if((val > node->data)) {
      insertHelper(node->right, val);
    }

  }

  public: 

    void insert(int val) {
      root = insertHelper(root, val);
    }

};

int main() {


  return 0;
}