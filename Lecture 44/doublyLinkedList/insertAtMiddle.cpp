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

void insertAtTail(Node* &tail,int data){

    Node* temp=new Node(data);

    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    if(position==1){
        insertAtHead(head,data);
        return;
    }

    Node* temp=head;

    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* insertAtPosition=new Node(data);

    insertAtPosition->next=temp->next;
    temp->next->prev=insertAtPosition;
    temp->next=insertAtPosition;
    insertAtPosition->prev=temp;

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

    Node* head=NULL;
    Node* tail=node1;

    insertAtHead(head,11);

    print(head);

    insertAtHead(head,13);

    print(head);

    insertAtHead(head,8);

    print(head);

    insertAtTail(tail,25);

    print(head);

    insertAtPosition(head,tail,2,100);

    print(head);

    insertAtPosition(head,tail,1,101);

    print(head);

    insertAtPosition(head,tail,8,102);

    print(head);

    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;

    return 0;
}