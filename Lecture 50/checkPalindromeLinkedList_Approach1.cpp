#include<iostream>
#include<vector>

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

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

bool checkPalindrome(vector<int> arr){

    int n=arr.size();
    int s=0;
    int e=n-1;

    while(s<=e){
        if(arr[s]!=arr[e]) return false;
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(Node* head){

    //step 1 create an array
    vector<int> arr;

    //step 2 copy Linked list content into array
    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    //step 3 check array for palindrome
    return checkPalindrome(arr);
}



int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);

    print(head);

    if(isPalindrome(head)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    return 0;
}