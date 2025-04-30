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

    //destructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"memory has been free for node with data:"<<value<<endl;
    }
};

void insertAtHead(Node* &head,int data){

    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int data){

    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    if(position==1){
        insertAtHead(head,data);
        return;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* insertAtPosition=new Node(data);
    insertAtPosition->next=temp->next;
    temp->next=insertAtPosition;

}

void deleteNode(Node* &head,Node* &tail,int position){

    if(position==1){
        Node* temp=head;
        head=head->next;

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
        prev->next=NULL;
        delete curr;
        return;
    }

    prev->next=curr->next;
    delete curr;
    }

}

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    print(head);

    insertAtTail(tail,12);

    print(head);

    insertAtTail(tail,15);

    print(head);
    
    insertAtPosition(head,tail,4,22);

    print(head);

    deleteNode(head,tail,4);

    print(head);

    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;

    return 0;   
}