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

Node* middleOfLinkedList(Node* head){

    int size=0;
    Node* temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }

    int mid=size/2 +1;
    Node* middle=head;
    while(middle->data!=mid){
        middle=middle->next;
    }
    return middle;
}

int main(){
    Node *node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,2);

    insertAtTail(head,tail,3);

    insertAtTail(head,tail,4);

    insertAtTail(head,tail,5);

    insertAtTail(head,tail,6);

    print(head);

    Node* middle=middleOfLinkedList(head);

    cout<<"Middle Linked list:";

    print(middle);

    return 0;
}