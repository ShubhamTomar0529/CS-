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
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }

}

Node* getMiddle(Node* head){

    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}

Node* reverse(Node* head){

    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

bool isPalindrome(Node* head){
    
    if(head==NULL || head->next==NULL) return true;

    //step 1:find middle
    Node* middle=getMiddle(head);

    //step2: reverse middle->next
    Node* temp=middle->next;
    middle->next=reverse(temp);

    //step3: compare first half and second half
    Node* head1=head;
    Node* head2=middle->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            temp=middle->next;
            middle->next=reverse(temp);
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    temp=middle->next;
    middle->next=reverse(temp);
    return true;
}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){

    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,2);
    insertAtTail(head,tail,1);

    print(head);

    if(isPalindrome(head)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    return 0;
}
