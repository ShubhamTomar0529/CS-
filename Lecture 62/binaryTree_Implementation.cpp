#include<iostream>

using namespace std;

//Binary Tree is a non linear data structure where one node can be connected to multiple nodes

/*
1)Node: One entity of a binary tree is a node. It contains the data of binary tree
2)Binary Tree: A tree in which every node has <=2 child
3)Root: Top node of the tree
4)Children: The next node below any node which is connected to it is called child
5)Parent: Vice-versa
6)Sibling: Nodes which have same parent
7)Ancestor:
8)Descendant:
9)Leaf: A node which has no child
*/

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

    root = buildTree(root);

    return 0;
}