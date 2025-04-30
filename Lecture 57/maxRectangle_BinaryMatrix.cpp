#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
#include<algorithm>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr){

    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for(int i=arr.size()-1;i>=0;i--){

        while(s.top()!=-1 && arr[i] <= arr[s.top()]){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);

    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr){

    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for(int i=0;i<arr.size();i++){

        while(s.top()!=-1 && arr[i] <= arr[s.top()]){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);

    }
    return ans;
    
}

int largestRectangularArea(vector<int> &arr,int n){

    vector<int> prev = prevSmallerElement(arr);

    vector<int> next = nextSmallerElement(arr);

    int maxArea = INT_MIN;

    for(int i=0;i<n;i++){
        
        int length = arr[i];

        if(next[i]==-1){
            next[i] = n;
        }

        int breadth = next[i]-prev[i]-1;

        maxArea=max(maxArea,length*breadth);
    }
    return maxArea;
}

int maxRectangle(vector<vector<int>> &mat){

    int area = largestRectangularArea(mat[0],mat[0].size());

    for(int i=1;i<mat.size();i++){

        for(int j=0;j<mat[0].size();j++){

            if(mat[i][j]!=0){
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }
            else{
                mat[i][j] = 0;
            }

        }
        area = max(area,largestRectangularArea(mat[i],mat[0].size()));
    }
    return area;
}

int main(){

    vector<vector<int>> mat = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};

    cout<<"Maximum area: "<<maxRectangle(mat);

    return 0;
}