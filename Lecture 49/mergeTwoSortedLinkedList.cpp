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

Node* solve(Node* first,Node* second){


    //if only one element is present in first list
    if(first->next==NULL){
        first->next=second;
        return first;
    }

    Node* curr1=first;
    Node* next1=curr1->next;

    Node* curr2=second;
    Node* next2=curr2->next;

    while(next1!=NULL && curr2!=NULL){
        
        if(curr2->data>=curr1->data && curr2->data<=next1->data){

            //add nodes in between the first list
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            //updating pointers
            curr1=curr2;
            curr2=next2;

        }
        else{

            //curr1 and next1 ko aage badhao
            curr1=next1;
            next1=next1->next;

            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }

        }

    }
    return first;
}

Node* sortTwoLists(Node* first,Node* second){

    if(first==NULL) return second;
    if(second==NULL) return first;

    if(first->data<=second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }

}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;

}

int main(){

    Node* head1=NULL;
    Node* tail1=NULL;

    insertAtTail(head1,tail1,1);
    insertAtTail(head1,tail1,4);
    insertAtTail(head1,tail1,5);

    print(head1);

    Node* head2=NULL;
    Node* tail2=NULL;
    
    insertAtTail(head2,tail2,2);
    insertAtTail(head2,tail2,3);
    insertAtTail(head2,tail2,5);

    print(head2);

    Node* ans=sortTwoLists(head1,head2);

    print(ans);

    return 0;
}