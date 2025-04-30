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

void print(Node* head){

    while (head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    
    cout<<endl;
}

void insertAtTail(Node* &head,Node* &tail,int data){

    if(tail==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }

}

Node* floydDetectLoop(Node* head){
    //empty list
    if(head==NULL) return NULL;

    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
        if(slow==fast) return slow;
    }

    return NULL;
}

Node* beginningLoop(Node* head){
    if(head==NULL) return NULL;

    Node* intersection=floydDetectLoop(head);
    Node* slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }

    return slow;
}

void removeLoop(Node*head){

    if(head==NULL) return;

    Node* startOfLoop=beginningLoop(head);
    Node* temp= startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }

    temp->next=NULL;
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,12);

    insertAtTail(head,tail,15);

    insertAtTail(head,tail,22);

    tail->next=head->next;

    if(floydDetectLoop(head)){
        cout<<"Loop/cycle is present in the linked list"<<endl;
    }
    else{
        cout<<"Loop/cycle is not present in the linked list"<<endl;
    }

    Node* loop=beginningLoop(head);
    cout<<"loop starts at:"<<loop->data<<endl;

    removeLoop(head);

    print(head);

    return 0; 
}