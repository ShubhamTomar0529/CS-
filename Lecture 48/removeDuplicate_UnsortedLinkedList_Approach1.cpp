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

Node* removeDuplicate(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;

        while (temp->next != NULL) {
            if (curr->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next; 
                delete duplicate; 
            } 
            else {
                temp = temp->next; 
            }
        }

        curr = curr->next;
    }
    return head;
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