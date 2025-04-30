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

Node* reverseNode(Node* head){
    
    //base case
    if(head==NULL || head->next==NULL) return head;

    Node* chotaHead=reverseNode(head->next);

    head->next->next=head;
    head->next=NULL;

    return chotaHead;
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

    insertAtTail(head,tail,5);

    insertAtTail(head,tail,7);

    insertAtTail(head,tail,9);

    print(head);

    Node* reverse=reverseNode(head);

    print(reverse);


    return  0;
}