#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void insertAtTail(Node* &head,Node* &tail,int data){

    if(tail==NULL){
        Node* temp= new Node(data);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
    }

}

void reverseNode(Node* &head){

    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    head=prev;
}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;

}




int main(){

    Node* node1=new Node(3);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,5);

    insertAtTail(head,tail,7);

    print(head);

    reverseNode(head);

    print(head);

    return 0;
}