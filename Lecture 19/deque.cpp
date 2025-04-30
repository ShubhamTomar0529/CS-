#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"First Index Element:"<<d.at(1)<<endl;
    cout<<"front:"<<d.front()<<endl;
    cout<<"back"<<d.back()<<endl;

    cout<<"empty or not->"<<d.empty()<<endl;

    cout<<"Size before erase:"<<d.size()<<endl;
    cout<<"Max size before erase:"<<d.max_size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"Size before erase:"<<d.size()<<endl;
    cout<<"Max size before erase:"<<d.max_size()<<endl;

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}