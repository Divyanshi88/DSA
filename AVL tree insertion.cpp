#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    int key;
    Node *left, *right;
    int height;
};

// Get height of the node
int height(Node *N) {
    return (N == nullptr) ? 0 : N->height;
}

// Get balance factor of node N
int getBalance(Node *N) {
    return (N == nullptr) ? 0 : height(N->left) - height(N->right);
}

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotate subtree rooted with y
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert a node
Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Heavy (Right Rotation)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Heavy (Left Rotation)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right Case (Left Rotate + Right Rotate)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (Right Rotate + Left Rotate)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main function\int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of the AVL tree: ";
    inorder(root);
    cout << endl;
    return 0;
}
// Output: Inorder traversal of the AVL tree: 10 20 25 30 40 50