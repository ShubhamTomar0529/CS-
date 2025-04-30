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

    //creating a tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order traversal
    cout<<"Printing Level Order Traversal: "<<endl;
    levelOrderTraversal(root); 


    return 0;
}