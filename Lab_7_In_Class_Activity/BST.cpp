#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node* insertNode(struct node* root, int key)
{
    // Step 1: Tree is empty
    if (root == NULL)
    {
        struct node* newNode = new node;
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Step 2: Insert in the left subtree
    if (key < root->key)
    {
        root->left = insertNode(root->left, key);
    }
    // Step 3: Insert in the right subtree
    else if (key > root->key)
    {
        root->right = insertNode(root->right, key);
    }

    // Step 4: Key already exists
    return root;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Step 1: Tree is empty
  if (root == NULL) {
    return NULL;
  }

  // Step 2: Delete from the left subtree
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  // Step 3: Delete from the right subtree
  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }
  // Step 4: Delete the current node
  else {
    // Case 1: No children
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    // Case 3: Two children
    else {
      // Find the minimum node in the right subtree
      struct node *minRight = root->right;
      while (minRight->left != NULL) {
        minRight = minRight->left;
      }
      // Replace the current node with the minimum node
      root->key = minRight->key;
      // Recursively delete the minimum node from the right subtree
      root->right = deleteNode(root->right, minRight->key);
    }
  }

  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
