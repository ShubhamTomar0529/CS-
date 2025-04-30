#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr,int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){

        while(arr[i] < s.top()){
            s.pop();
        }

        ans[i] = s.top();
        s.push(arr[i]);

    }
    return ans;
}

int main(){

    int n;
    cout<<"Enter the number of elements you want in the vector:";
    cin>>n;
    
    vector<int> arr(n);

    cout<<"Enter the elements in the vector"<<endl;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    vector<int> ans = nextSmallerElement(arr,arr.size());

    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}