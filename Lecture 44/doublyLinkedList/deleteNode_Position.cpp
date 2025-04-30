#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"memory has been free for node with data:"<<value<<endl;
    }

};

void insertAtHead(Node* &head,Node* &tail,int data){

    if(head==NULL){
        Node*temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){

    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp=new Node(data);

    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }

    Node* temp=head;

    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(head,tail,data);
        return;
    }

    Node* insertAtPosition=new Node(data);

    insertAtPosition->next=temp->next;
    temp->next->prev=insertAtPosition;
    temp->next=insertAtPosition;
    insertAtPosition->prev=temp;

}

void deleteNode(Node* &head,Node* &tail,int position){

    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;  
        head=temp->next;   
        temp->next=NULL;
        //free memory
        delete temp;
    }
    else{

    Node* curr=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }

    if(curr->next==NULL){
        tail=prev;
        curr->prev=NULL;
        prev->next=NULL;
        delete curr;
        return;
    }

    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
     
    delete curr;
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


    Node* head=NULL;
    Node* tail=NULL;

    insertAtHead(head,tail,11);

    print(head);

    insertAtHead(head,tail,13);

    print(head);

    insertAtHead(head,tail,8);

    print(head);

    insertAtTail(tail,tail,25);

    print(head);

    insertAtPosition(head,tail,2,100);

    print(head);

    insertAtPosition(head,tail,1,101);

    print(head);

    insertAtPosition(head,tail,7,102);

    print(head);

    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;

    deleteNode(head,tail,7);
    print(head);

    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;



    return 0;
}