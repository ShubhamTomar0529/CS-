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

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;

}

//tortoise and hare approach
Node* getMid(Node* head) {
        Node* slow=head;
        Node* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

Node* merge(Node* left,Node* right){

    if(left==NULL) return right;
    if(right==NULL) return left;

    Node* ans=new Node(-1);
    Node* temp=ans;

    //merge two sorted linked list
    while(left!=NULL && right!=NULL){

        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;  
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }

    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }

    ans=ans->next;
    return ans;
}

Node* mergeSort(Node* head){

    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //finding mid
    Node* mid=getMid(head);

    //breaking list into two halves
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;

    //recursive calls
    left=mergeSort(left);
    right=mergeSort(right);

    //merge two sorted list
    Node* result= merge(left,right);

    return result;

}

int main(){
     
    Node* head=NULL;
    Node* tail=NULL;

    insertAtTail(head,tail,3);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,9);

    Node* ans=mergeSort(head);
    print(ans);

    return 0;
}