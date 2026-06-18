#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
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

void InsertAtHead(Node*& head, int d) {
    // Create a new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

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

void print(Node*& head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int position, Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        // Free memory of start node
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);

    // Head points to node1
    Node* head = node1;
    Node* tail = node1;

    print(head);

    InsertAtTail(tail, 12);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertAtPosition(head, 1, 22);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(4, head);
    print(head);

    return 0;
}
