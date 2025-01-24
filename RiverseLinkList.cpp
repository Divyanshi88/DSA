#include <iostream>
using namespace std;

class Node {
public:
    int d;
    Node* next;

    // Constructor to initialize a new node
    Node(int data) {
        d = data;
        next = NULL;
    }
};

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->d << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a node at the head of the list
void InsertAtHead(Node*& head, int d) {
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at a specific position
void InsertAtPosition(Node*& head, int position, int d) {
    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    // Creating a node for d
    Node* NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}

// Function to reverse the linked list
Node* reverseLinkedList(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

int main() {
    
    Node* node1 = new Node(10);

    Node* head = node1;

    
    InsertAtPosition(head, 1, 22);

    
    print(head);

    InsertAtPosition(head, 2, 2);

    
    print(head);
    InsertAtPosition(head, 3, 12);

    
    print(head);
    InsertAtPosition(head, 4, 8);

    
    print(head);
    InsertAtPosition(head, 5, 100);

    
    print(head);
    InsertAtPosition(head, 6, 78);

    
    print(head);
    InsertAtPosition(head, 7, 89);

    
    print(head);
    InsertAtPosition(head, 8, 17);

    
    print(head);
    InsertAtPosition(head, 9, 82);

    
    print(head);


    head = reverseLinkedList(head);

    print(head);

    return 0;
}
