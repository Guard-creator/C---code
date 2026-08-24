#include <iostream>
#include <queue>
#include <vector>

// Binary Tree Traversal
// Going through a Tree by visiting every node, one node at a time, is called traversal.

// Breadth First Search (BFS) is when the nodes on the same level are 
// visited before going to the next level in the tree. This means that 
// the tree is explored in a more sideways direction.

// Depth First Search (DFS) is when the traversal moves down the tree 
// all the way to the leaf nodes, exploring the tree branch by branch 
// in a downwards direction.

// There are three different types of DFS traversals:
// pre-order
// in-order
// post-order

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
Node* build(std::vector<int> pattren) {

  idx++;

  if(pattren[idx] == -1) return NULL;

  Node* root = new Node(pattren[idx]);
  root->left = build(pattren);
  root->right = build(pattren);

  return root;

}

// PreOrder Traversal 
// root, left, right
void preOrder(Node* root) {

  if(root == NULL) return;

  std::cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);

}

// Inorder Traversal 
// left, root, right
void inOrder(Node* root) {

  if(root == NULL) return;

  inOrder(root->left);
  std::cout << root->data << " ";
  inOrder(root->right);

}

// postOrder Traversal 
// left, right, root
void postOrder(Node* root) {

    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";

}

// This is Breath Tree Traversal
// level order traverl 
// to go through the tree 
// which we travel the tree by levels
void levelOrder(Node* root) {

  std::queue<Node*> que;

  que.push(root);
  que.push(NULL); // to start on next line

  while(!que.empty()) {

    Node* node = que.front();
    que.pop();

    // this will know us when the next level is gonna start
    if(node == NULL) {
      if(!que.empty()) {
        std::cout << std::endl;
        que.push(NULL);
        continue;
      } else {
        break;
      }
    }

    std::cout << node->data << " ";

    if(node->left != NULL) {
      que.push(node->left);
    }
    if(node->right != NULL) {
      que.push(node->right);
    }

  }

}

int main() {

  std::vector<int> pattren = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node* root = build(pattren);

  std::cout << "PreOrder: ";
  preOrder(root);
  std::cout << std::endl;

  std::cout << "InOrder: ";
  inOrder(root);
  std::cout << std::endl;

  std::cout << "postOrder: ";
  postOrder(root);
  std::cout << std::endl;

  std::cout << "levelOrder: \n";
  levelOrder(root);
  std::cout << std::endl;

  return 0;
}