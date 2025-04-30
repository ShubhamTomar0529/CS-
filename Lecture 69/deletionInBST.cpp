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

//H.W: inorder predecessor and inorder successor    

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

Node* deleteFromBST(Node* root,int val){

    //T.C :- O(h) in average case, O(n) in skew 

    //base case
    if(root==NULL) return root;
    
    if(root->data==val){

        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }

    }
    else if(root->data>val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
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

int minVal(Node* root){

    //T.C: O(h)
    
    Node* temp = root;

    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp->data;

}

int maxVal(Node* root){

    Node* temp = root;

    while(temp->right!=NULL){
        temp = temp->right;
    }

    return temp->data;

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

    cout<<"Min value in BST: "<<minVal(root)<<endl;
    cout<<"Max value in BST: "<<maxVal(root)<<endl;

    root = deleteFromBST(root,30);

    return 0;
}