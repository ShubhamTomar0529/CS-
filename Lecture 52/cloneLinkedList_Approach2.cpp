#include<iostream>
#include<unordered_map>

using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }

};

void insertAtTail(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* copyRandomList(Node* head) {

    //step 1:- create a clone list and copy the values and next pointers
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;

    Node* temp=head;

    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }

    //step 2:- map original and clone linked list
    unordered_map<Node*,Node*>oldToNewNode;

    Node* originalNode=head;
    Node* cloneNode=cloneHead;
    while(originalNode!=NULL){
        oldToNewNode[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }

    // step 3: copy random ptrs using maps

    originalNode=head;
    cloneNode=cloneHead;
    while(originalNode!=NULL){
        cloneNode->random=oldToNewNode[originalNode->random];
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }

    return cloneHead;
}