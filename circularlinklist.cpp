#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int val = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

// Function to insert a node into a circular linked list
void insertNode(Node*& tail, int element, int d) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    } 
    // Non-empty list
    else {
        Node* curr = tail;

        // Traverse the list to find the element
        while (curr->data != element) {
            curr = curr->next;
        }

        // Element found -> curr represents the node with the given element
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

        // Update tail if the new node is inserted after the current tail
        if (curr == tail) {
            tail = temp;
        }
    }
}

// Function to print the circular linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail->next; // Start from the first node
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); // Stop when we complete the cycle
    cout << endl;
}

// Function to delete a node from the circular linked list
void deleteNode(Node*& tail, int val) {
    if (tail == NULL) {
        cout << "List is empty, please check again." << endl;
        return;
    }

    // Non-empty list
    Node* prev = tail;
    Node* curr = prev->next;

    // Traverse the list to find the node with the value
    while (curr->data != val) {
        prev = curr;
        curr = curr->next;

        // If we've looped back to the tail, the value is not found
        if (curr == tail->next) {
            cout << "Value " << val << " not found in the list." << endl;
            return;
        }
    }

    // Node found
    prev->next = curr->next;

    // If we're deleting the only node in the list
    if (curr == prev) {
        tail = NULL;
    } 
    // If we're deleting the tail node
    else if (curr == tail) {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}
