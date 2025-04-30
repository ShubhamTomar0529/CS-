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

    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"memory has been free for the data with the value:"<<val<<endl;
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

void sortLinkedList(Node* &head){
    
}

Node* removeDuplicate(Node* head) {
    if(head==NULL || head->next==NULL) return NULL;
    

    //sorting linked list
    sortLinkedList(head);

    //removing duplicate from sorted linked list
    Node* curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            Node* next_next= curr->next->next;
            Node* nodeToDelete=curr->next;
            delete(nodeToDelete);
            curr->next=next_next;

        }
        else{
            curr=curr->next;      
        }
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

    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,3);


    print(head);

    Node* unique=removeDuplicate(head);

    print(unique);

    return 0;
}