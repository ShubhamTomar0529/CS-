#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        next=NULL;
        random=NULL;
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
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    Node* temp=head;

    while(temp!=NULL){
        insertAtTail(ansHead,ansTail,temp->data);
        temp=temp->next;
    }


    Node* ansCurr=ansHead;
    Node* curr=head;

    while(curr!=NULL){
        temp=head;
        int cnt=1;

        while(temp!=curr->random && temp!=NULL){
            temp=temp->next;
            cnt++;
        }

        temp=ansHead;
        int ansCnt=1;
        while(ansCnt!=cnt){
            temp=temp->next;
            ansCnt++;
        }

        ansCurr->random=temp;

        curr=curr->next;
        ansCurr=ansCurr->next;

    }
    return ansHead;
}
