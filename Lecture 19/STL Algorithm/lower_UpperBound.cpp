#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    vector<int>v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Lower bound:"<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"Upper bound:"<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    return 0;
}