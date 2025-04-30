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

void inOrder(Node* root){
    if(root==NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void preOrder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* root){
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp==NULL){

            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* &root,int data){

    //T.C:- O(logn)

    if(root == NULL){
        root = new Node(data);
        return root;   
    }

    if( data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
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

int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST:"<<endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    return 0;
}