#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>

using namespace std;

vector<int> nextSmallerElements(vector<int> arr,int n){

    stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){

            while(s.top()!=-1 && arr[i] <= arr[s.top()]){
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;

}

vector<int> prevSmallerElements(vector<int> arr,int n){

    stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for(int i=0;i<n;i++){

            while(s.top()!=-1 && arr[i] <= arr[s.top()]){
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
    return ans;
}

int largestRectangularArea(vector<int> &arr){

    int n = arr.size();

    vector<int> next;
    next = nextSmallerElements(arr,n);

    vector<int> prev;
    prev = prevSmallerElements(arr,n);

    int maxArea = INT_MIN;

    for(int i=0;i<n;i++){

        int length = arr[i];
        
        if(next[i]==-1){
            next[i] = n;
        }

        int breadth = next[i]-prev[i]-1;

        if(length*breadth>maxArea) maxArea =  length*breadth;
    }

    return maxArea;

}

int main(){

    vector<int> heights={2,1,5,6,2,3};

    cout<<"Largest rectangular area is: "<<largestRectangularArea(heights);
    cout<<endl;

    return 0;
}