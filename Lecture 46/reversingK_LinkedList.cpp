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

Node* reverseK(Node* head,int k){

    //base case
    if(head==NULL) return NULL;

    //check if there are less than k nodes
    Node* temp=head;
    int count=0;

    while(temp!=NULL && count<k){
        temp=temp->next;
        count++;
    }

    if(count<k) return head;

    //step 1:reverse first k nodes
    Node* forward=NULL;
    Node* curr=head;
    Node* prev=NULL;
    count=0;
    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }

    //step2: recursion dekh lega
    if(forward!=NULL){
        head->next=reverseK(forward,k);
    }

    //step3:return head(return head of reversed list)
    return prev;
}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

int main(){

    Node* node1=new Node(3);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,7);
    
    insertAtTail(head,tail,8);

    insertAtTail(head,tail,11);

    insertAtTail(head,tail,17);

    insertAtTail(head,tail,2);

    print(head);

    Node* kReverse=reverseK(head,2);

    print(kReverse);

    return 0;
}