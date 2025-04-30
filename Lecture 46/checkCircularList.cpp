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
        cout<<"memory has free for the data with the value:"<<val<<endl;
    }

};

void insertNode(Node* &tail,int element,int data){

    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=tail;
    }
    else{
        //non empty list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        //element found
        Node* temp= new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }

}

void deleteNode(Node* &tail,int value){

    if(tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;

        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail=prev;
        }

        delete curr;
    }
    
}

bool isCircularList(Node* head){

    if(head==NULL) return true;

    Node* temp=head->next;

    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    if(temp==head) return true;

    return false;
}

void print(Node *tail){
    Node* temp=tail;
    
    if(tail==NULL){
        cout<<"List is empty";
        return; 
    }

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);

    cout<<endl;
}

int main(){

    Node* node1 = NULL;
    Node* tail=node1;

    insertNode(tail,5,3);
    
    print(tail);

    insertNode(tail,3,5);

    print(tail);

    if(isCircularList(tail)){
        cout<<"Linked list is Circular in nature"<<endl;
    }
    else{
        cout<<"Linked list is not Circular"<<endl;
    }
    return 0;
}