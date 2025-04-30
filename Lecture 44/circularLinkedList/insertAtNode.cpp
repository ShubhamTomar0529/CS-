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
        cout<<"memory has been free for the data:"<<val<<endl;
    }

};

void insertNode(Node* &tail,int element,int data){
    //assuming that the element is present in the list

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

void print(Node* tail){

    Node* temp=tail;
    
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);

    cout<<endl;
}

int main(){
    
    Node* tail=NULL;

    //empty list
    insertNode(tail,5,3);

    print(tail);

    insertNode(tail,3,5);

    print(tail);

    insertNode(tail,5,7);

    print(tail);

    insertNode(tail,7,9);

    print(tail);

    insertNode(tail,5,6);

    print(tail);

    insertNode(tail,9,10);

    print(tail);

    insertNode(tail,3,4);

    print(tail);

    return 0;
}