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
        int val=this->data;
        if(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
        cout<<"memory has been free for data with value:"<<val<<endl;
    }

};

int main(){

    Node* node1=new Node(10);
    Node* tail=node1;
    
    return 0;
}