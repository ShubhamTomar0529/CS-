#include<iostream>
#include<vector>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){

    vector<int> result(n,-1);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                result[i]=arr[j];
                break;
            }
        }
    } 
    return result;

}

int main(){

    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> ans = nextSmallerElement(v,v.size());

    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}