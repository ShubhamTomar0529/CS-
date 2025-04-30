#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int>v;

    cout<<"Capacity:"<<v.capacity()<<endl;
    
    v.push_back(1);
    cout<<"Capacity:"<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity:"<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity:"<<v.capacity()<<endl;

    cout<<"Size:"<<v.size()<<endl;

    cout<<"Element at 2nd index:-"<<v.at(2)<<endl;

    cout<<"front:"<<v.front()<<endl;
    cout<<"back:"<<v.back()<<endl;

    cout<<"before pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();
    cout<<"After pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl; 

    cout<<"before clear capacity:"<<v.capacity()<<endl;
    cout<<"before clear size:"<<v.size()<<endl;

    v.clear();

    cout<<"after clear size:"<<v.size()<<endl;
    cout<<"after clear capacity:"<<v.capacity()<<endl;

    //how to declare a vector if we already know the size of vector
    vector<int>a(5,1);

    //copying the vector a to vector b
    vector<int>b(a);

    for(int i:b){
        cout<<i<<" ";
    }

    return 0;
}