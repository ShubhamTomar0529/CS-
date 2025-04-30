#include<iostream>
#include<vector>

using namespace std;

int celebrity(vector<vector<int> >& mat){

    int n = mat.size();

    for(int i=0;i<n;i++){
        bool isCelebrity = true;    
        for(int j=0;j<n;j++){

            if(j!=i){
                if(mat[i][j]==1){
                    isCelebrity = false;
                    break;
                }
            }
        }

        if(isCelebrity==true){

            for(int k=0;k<n;k++){

                if(k!=i && mat[k][i]==0){
                    isCelebrity = false;
                    break;
                }
            }

        }
        if(isCelebrity==true) return i;
    }
    return -1;
}

int main(){

    vector<vector<int>> mat = {{0,1,0},{0,0,0},{0,1,0}};

    cout<<"Celebrity is present at index: "<<celebrity(mat)<<endl;

    return 0;
}