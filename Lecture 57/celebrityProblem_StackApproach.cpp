#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int celebrity(vector<vector<int> >& mat) {
        
        stack<int> s;
        
        int n = mat.size();
        
        //step 1: push all elements in stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        //step 2: check for celebrity(potential)
        while(s.size()!=1){
            
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(mat[a][b]==1){
                s.push(b);
            }
            else{
                s.push(a);
            }
            
        }
        
        //step 3: single elements in stack(Potential celebrity)
        int candidate = s.top();
        for(int i=0;i<n;i++){
            if(i!=candidate && (mat[candidate][i]==1 || mat[i][candidate]==0)) return -1;
        }
        
        
        return s.top();
        
    }

int main(){

    vector<vector<int>> mat = {{0,1,0},{0,0,0},{0,1,0}};

    cout<<"Celebrity is present at index: "<<celebrity(mat)<<endl;

    return 0;
}