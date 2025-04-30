#include<iostream>
#include<map>

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

bool floydDetectLoop(Node* head){

    if(head==NULL) return false;

    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){

        //moving fast 2 times  
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;

        //moving slow 1 times
        slow=slow->next;

        if(slow==fast){
            cout<<"present at:"<<slow->data<<endl;
            return true;
        }
    }

    return false;
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
        cout<<"Loop/cycle is present in the linked list";
    }
    else{
        cout<<"Loop/cycle is not present in the linked list";
    }

    return 0;
}