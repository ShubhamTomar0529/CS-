#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

void levelOrderTraversal(Node* root){

    if(root==NULL) return;

    queue<Node*> q;

    q.push(root);
    q.push(NULL);


    while(!q.empty()){

        Node* temp = q.front();

        q.pop();

        

        if(temp==NULL){ //purana level end
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout<<temp->data<< " ";

            if(temp->left){
                q.push(temp->left);
            }
    
            if(temp->right){
                q.push(temp->right);
            } 
        }

    }

}

Node* insertIntoBST(Node* root,int d){

    //Time Complexity: O(logn) 

    //base case
    if(root==NULL){
        root = new Node(d);
        return root; 
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right,d);
    }
    else{
        root->left = insertIntoBST(root->left,d);
    }

    return root;

}

void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data!=-1){

        root = insertIntoBST(root,data);
        cin>>data;

    }

}

bool searchInBST(Node* root,int data){

    Node* temp = root;

    while(temp!=NULL){

        if(temp->data==data){
            return true;
        }
        else if(temp->data>data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return false;
}

int main(){

    Node* root = NULL;

    cout<<"Enter the data to create the BST: ";
    takeInput(root);

    cout<<"Printing the BST:"<<endl;
    levelOrderTraversal(root);

    if(searchInBST(root,4)){
        cout<<"Target found"<<endl;
    }
    else{
        cout<<"Target Not Found"<<endl;
    }

    return 0;
}