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

void insertAtHead(Node* &head,int data){

    Node* temp=new Node(data);
    temp->next=head;
    head=temp;

};

void insertAtTail(Node* &tail,int data){

    Node *temp=new Node(data);
    tail->next=temp;
    tail=temp;

}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    //insert at Start/position first

    if(position==1){
        insertAtHead(head,data);
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
        insertAtTail(tail,data);
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
    
    Node *node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;


    print(head);

    insertAtPosition(head,tail,1,12);

    print(head);

    insertAtTail(tail,15);

    print(head);

    insertAtPosition(head,tail,4,22);

    print(head);

    return 0;
}