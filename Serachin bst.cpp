#include <iostream>
using namespace std;

struct Node {  
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* searchBST(Node* root, int key) {  
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    if (root->data > key) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

int main() {
    // Creating a sample BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    // Corrected if condition
    if (searchBST(root, 5) == NULL) {
        cout << "Key doesn't exist";
    } else {
        cout << "Key exists";
    }

    return 0;
}
