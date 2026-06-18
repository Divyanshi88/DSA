#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    //deconstrutor
    ~Node() {
        int value = this->data;
        // Free memory
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Traversing a linked list
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Give length of the linked list
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at head
void insertAtHead(Node*& head, Node*& tail, int d) {
    if (head == NULL) { // If the list is empty
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at tail
void insertAtTail(Node*& tail, Node*& head, int d) {
    if (tail == NULL) { // If the list is empty
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insert at a specific position
void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position == 1) { // Inserting at the head
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the position before the desired position
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) { // Position is beyond the current list length
        cout << "Position is out of bounds. Inserting at the tail instead." << endl;
        insertAtTail(tail, head, d);
        return;
    }

    if (temp->next == NULL) { // Inserting at the tail
        insertAtTail(tail, head, d);
        return;
    }

    // Creating a new node for the given data
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(int position, Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        
        // Free memory of start node
        temp->next->prev =NULL;
        
        head=temp->next;
        
        temp->next = NULL;


        
        delete temp;
    } else {
        // Deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }

       
        curr->next = NULL;
        prev->next = curr-> next;
        curr->next=NULL;


        delete curr;
    }
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Initially empty list
    print(head);

    // Inserting at the head
    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 8);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    // Inserting at the tail
    insertAtTail(tail, head, 25);
    print(head);

    // Inserting at specific positions
    insertAtPosition(tail, head, 2, 100);
    print(head);

    insertAtPosition(tail, head, 1, 101);
    print(head);

    insertAtPosition(tail, head, 7, 102);
    print(head);

    deleteNode(7, head);
    print(head);

    return 0;
}
