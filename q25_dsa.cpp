#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtHead(Node* &head, int d){
    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail-> next = temp;
    tail = temp;

}
void InsertAtPosition( Node* &head, int position, int d){
    if(position==1){
        InsertAtHead(head, d);
    }
     Node* temp = head;
     int cnt =1;

     while(cnt<position-1){
        temp = temp->next;
        cnt++;
     }
     //creating a node for d
     Node* NodeToInsert= new Node(d);
     NodeToInsert -> next = temp -> next;
     temp -> next = NodeToInsert;


}

void print(Node* &head){
     Node* temp= head;

     while(temp != NULL){
        cout<<temp -> data <<" ";
        temp= temp -> next;
     }
     cout<<endl;
}
int main(){
    Node* node1= new Node(10);
   // cout<< node1 -> data <<endl;
    //cout<< node1 -> next <<endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

   InsertAtTail(tail, 12);

    print(head);
    InsertAtTail(tail, 15);
     print(head); 

    InsertAtPosition(head, 1,22);
     print(head);

    return 0;
}