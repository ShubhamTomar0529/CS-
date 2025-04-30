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

void insertAtHead(Node* &head,Node* &tail,int data){

    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
    }
    

};

void insertAtTail(Node* &head,Node* &tail,int data){


    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
    Node *temp=new Node(data);
    tail->next=temp;
    tail=temp;
    }
    

}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    //insert at Start/position first

    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }

    //insert between first and last position(exclusive)
    Node* temp=head;

    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp->next==NULL){
        //updating tail when inserting at last position
        insertAtTail(head,tail,data);
        return;
    }

    Node* insertAtPosition = new Node(data);
    insertAtPosition->next=temp->next;
    temp->next=insertAtPosition;

}

void print(Node* &head){

    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int main(){
    
    Node* head=NULL;
    Node* tail=NULL;


    insertAtHead(head,tail,10);

    print(head);

    insertAtHead(head,tail,15);

    print(head);

    insertAtPosition(head,tail,3,22);

    print(head);

    return 0;
}