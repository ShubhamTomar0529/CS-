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

void reverseNode(Node* &head,Node* prev,Node* curr){

    //base case
    if(curr==NULL){
        head=prev;
        return;
    }

    //recursion
    Node* forward=curr->next;
    reverseNode(head,curr,forward);
    curr->next=prev;
    
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

    reverseNode(head,NULL,head);

    print(head);

    return 0;
}