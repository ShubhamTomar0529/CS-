#include<iostream>
#include<map>

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

bool detectLoop(Node* head){
    //empty list
    if(head==NULL) return false;

    map<Node*,bool>visited;

    Node*temp=head;

    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            cout<<"Cycle is dpresent at node:"<<temp->data<<endl;
            return true;
        }
        
        //marking the node to be true if visited
        visited[temp]=true;

        //moving temp to next node
        temp=temp->next;
    }

    return false;
}

int main(){

    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,12);

    insertAtTail(head,tail,7);

    insertAtTail(head,tail,2);


    if(detectLoop(head)){
        cout<<"Loop/cycle is present in the linked list";
    }
    else{
        cout<<"Loop/cycle is not present in the linked list";
    }

    return 0;
}