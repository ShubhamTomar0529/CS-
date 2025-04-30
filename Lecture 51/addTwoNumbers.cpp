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

Node* add(Node* first,Node* second){
    int carry=0;

    Node* ansHead=NULL;
    Node* ansTail=NULL;
    while(first!=NULL && second!=NULL){
        int sum=carry+first->data+second->data;
        
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);

        carry=sum/10;
        first=first->next;
        second=second->next;
    }

    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        first=first->next;
    }

    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        second=second->next;
    }

    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
    }
    return ansHead;
}

Node* addTwoList(Node *first,Node* second){

    //step-1 :-reverse input linked list
    first=reverse(first);
    second=reverse(second);

    //step-2:- add two linked list
    Node* ans=add(first,second);

    //step-3:- reverse ans list
    ans=reverse(ans);

    return ans;
}

void print(Node *head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

int main(){
    
    Node* node1=new Node(4);
    Node* head1=node1;
    Node* tail1=node1;

    insertAtTail(head1,tail1,5);

    Node* node2=new Node(3);
    Node* head2=node2;
    Node* tail2=node2;

    insertAtTail(head2,tail2,4);
    insertAtTail(head2,tail2,5);

    Node* ans=addTwoList(node1,node2);

    print(ans);

    return 0;
}