#include<iostream>
#include<vector>

using namespace std;

int celebrity(vector<vector<int>> &mat){

    int n = mat.size();
    int candidate = 0;

    //Step 1: checking potential candidate
    for(int i=0;i<n;i++){
        if(mat[candidate][i]==1) candidate = i;
    }

    //Step 2: Verify if the candidate is actually a celebrity
    for(int i=0;i<n;i++){
        if(i!=candidate &&(mat[candidate][i]==1 || mat[i][candidate]==0)){
            return -1;
        }
    }

    return candidate;
}

int main(){

    vector<vector<int>> mat = {{0,1,0},{0,0,0},{0,1,0}};

    cout<<"Celebrity is present at index: "<<celebrity(mat)<<endl;

    return 0;
}