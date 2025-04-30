#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void insertAtTail(Node* &head,Node* &tail,int data){

    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
    }

}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

Node* middleOfLinkedList(Node* &head){

    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

int main(){
    Node *node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,2);

    insertAtTail(head,tail,3);

    insertAtTail(head,tail,4);

    insertAtTail(head,tail,5);

    print(head);

    Node* middle=middleOfLinkedList(head);

    cout<<"Middle Linked list:";

    print(middle);

    return 0;
}