#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){


    vector<int>d;

    d.push_back(1);
    d.push_back(3);
    d.push_back(6);
    d.push_back(7); 

    cout<<"Before rotating:";
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    rotate(d.begin(),d.begin()+1,d.end());
    cout<<"After rotating:";
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}


