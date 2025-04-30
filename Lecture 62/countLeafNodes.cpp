#include<iostream>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
      T data;
      BinaryTreeNode<T> *left;
      BinaryTreeNode<T> *right;

      BinaryTreeNode(T data) {
              this -> data = data;
              left = NULL;
              right = NULL;
      }
  };

void inorderCount(BinaryTreeNode<int> *root,int &count){

    if(root==NULL) return;

    inorderCount(root->left,count);

    if(root->right==NULL && root->left==NULL){
        count++;
    }

    inorderCount(root->right,count);

}

int noOfLeafNodes(BinaryTreeNode<int> *root){

    int count=0;
    
    inorderCount(root,count);

    return count;

}