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

Node* sortZeroOneTwo(Node* head){

    int zero=0;
    int one=0;
    int two=0;

    Node* temp=head;

    while(temp!=NULL){

        if(temp->data==0) zero++;
        else if(temp->data==1) one++;
        else two++;
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){

        if(zero!=0){
            temp->data=0;
            zero--;
        }
        else if(one!=0){
            temp->data=1;
            one--;
        }
        else{
            temp->data=2;
            two--;
        }
        temp=temp->next;
    }
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