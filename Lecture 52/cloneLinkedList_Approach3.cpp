#include<iostream>

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

Node* copyRandomList(Node* head){

    //step 1: create a clone list and copy values,pointers
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;

        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }

        //step 2:cloneNodes add in between original List
        Node* originalNode=head;
        Node* cloneNode=cloneHead;

        while(originalNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;

            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }

        //step 3:random pointer copy
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                }
            }
            else{
            temp->next=NULL;
            }
            temp=temp->next->next;
        }

        //step 4:revert changes done in step 2
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;

            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }   
            cloneNode=cloneNode->next;
        }

        //step 5: return cloneHead
        return cloneHead;
    

}