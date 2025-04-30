#include<iostream>
#include<list>

using namespace std;

int main(){

    list<int> l;

    l.push_back(1);
    l.push_front(2);

    cout<<"Empty or not"<<l.empty()<<endl;

    cout<<"Front:"<<l.front()<<endl;

    cout<<"Back:"<<l.back()<<endl;

    cout<<"Size:"<<l.size()<<endl;

    l.pop_back();
    for(int i:l){
        cout<<i<<" ";
    }   

    return 0;
}