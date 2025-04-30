#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

};

void insertAtHead(Node* &head,int data){

    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;

}

//traversing a doubly linked list
void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

//calculating length of doubly linked list
int getLength(Node* head){

    int size=0;

    while(head!=NULL){
        size++;
        head=head->next;
    }

    return size;
}

int main(){
    Node *node1=new Node(10);

    Node* head=node1;

    print(head);

    insertAtHead(head,11);

    print(head);

    insertAtHead(head,13);

    print(head);

    insertAtHead(head,8);

    print(head);

    return 0;
}