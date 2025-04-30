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

//BFS
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete traverse hogaya
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

void inOrderTraversal(Node* root){

    if(root==NULL) return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);

}

void preOrderTraversal(Node* root){

    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void postOrderTraversal(Node* root){

    if(root==NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(Node* &root){

    queue<Node*> q;
    cout<<"Enter the data for root"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();   

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

Node* buildTree(Node* root){

    cout<<"Enter the data for node:"<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);  
    
    return root;

}

int main(){

    Node* root = NULL;

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    /*
    //creating a tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<endl;
    //level order traversal
    cout<<"Printing Level Order Traversal: "<<endl;
    levelOrderTraversal(root); 

    cout<<endl;
    cout<<"Printing InOrder Traversal: "<<endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<endl;
    cout<<"Printing PreOrder Traversal: "<<endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<endl;
    cout<<"Printing PostOrder Traversal: "<<endl;
    postOrderTraversal(root);
    cout<<endl;
    */


    return 0;
}