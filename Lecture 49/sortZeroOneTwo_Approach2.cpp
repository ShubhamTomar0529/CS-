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

    Node* temp=new Node(data);
    if(tail==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }

}

void insertPtrTail(Node* &tail,Node* temp){

    tail->next=temp;
    tail=temp;

}

Node* sortZeroOneTwo(Node* head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail=zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail=oneHead;

    Node* twoHead = new Node(-1);  
    Node* twoTail=twoHead;

    Node* temp=head;

    //create seperate list 0s,1s and 2s
    while(temp!=NULL){

        if(temp->data==0){
            insertPtrTail(zeroTail,temp);
        }
        else if(temp->data==1){
            insertPtrTail(oneTail,temp);
        }
        else{
            insertPtrTail(twoTail,temp);
        }
        temp=temp->next;
    }

    //merge three list
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    //setup head 
    head=zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){

    Node* head=NULL;
    Node* tail=NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,0);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);

    print(head);

    Node* ans=sortZeroOneTwo(head);

    print(ans);

    return 0;
}