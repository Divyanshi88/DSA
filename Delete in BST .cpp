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

Node* inorderSucc(Node* root) {
    Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteinBST(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > key) {
        root->left = deleteinBST(root->left, key);
    } 
    else if (root->data < key) {
        root->right = deleteinBST(root->right, key);
    } 
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteinBST(root, 5);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
// Output: Inorder before deletion: 1 2 3 4 5 6
// Inorder after deletion: 1 2 3 4 6
// Complexity Analysis:
// Time Complexity: O(H), where H is the height of the BST. The time complexity of deleteinBST() is defined by the height of the tree.
// Space Complexity: O(H), where H is the height of the BST. The space complexity of deleteinBST() is defined by the space used by the recursive call stack. In the worst case, the height of the BST can be H, leading to O(H) space complexity.
//
// Approach 2: Iterative Approach
// Algorithm:
// The iterative approach is similar to the recursive approach. We will traverse the BST to find the node to be deleted. If the node is found, we will delete it using the following steps:
// If the node to be deleted is a leaf node, we will simply remove it.
// If the node to be deleted has only one child, we will replace the node with its child.
// If the node to be deleted has two children, we will find the inorder successor of the node. The inorder successor is the smallest node in the right subtree of the node. We will replace the node with the inorder successor and delete the inorder successor from the right subtree.
// Let's implement the iterative approach to delete a node in a BST:
// C++ program to delete a node in a BST
#include <iostream>
#include <stack>                                    

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

Node* inorderSucc(Node* root) {
    Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteinBST(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    Node* curr = root;
    Node* prev = NULL;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (curr->data < key) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (curr == NULL) {
        return root;
    }

    if (curr->left == NULL) {
        if (prev == NULL) {
            root = curr->right;
        } else if (prev->left == curr) {
            prev->left = curr->right;
        } else {
            prev->right = curr->right;
        }
        delete curr;
    } else if (curr->right == NULL) {
        if (prev == NULL) {
            root = curr->left;
        } else if (prev->left == curr) {
            prev->left = curr->left;
        } else {
            prev->right = curr->left;
        }
        delete curr;
    } else {
        Node* temp = inorderSucc(curr->right);
        curr->data = temp->data;
        curr->right = deleteinBST(curr->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteinBST(root, 5);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}