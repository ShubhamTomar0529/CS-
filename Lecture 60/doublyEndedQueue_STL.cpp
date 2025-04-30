#include<iostream>
#include<deque>

using namespace std;

int main(){

    deque<int> dq;

    dq.push_front(12);
    dq.push_back(14);

    cout<<"Front of deque: "<<dq.front()<<endl;
    cout<<"Back of deque: "<<dq.back()<<endl;

    dq.pop_front();

    cout<<"Front of deque: "<<dq.front()<<endl;
    cout<<"Back of deque: "<<dq.back()<<endl;
    
    dq.pop_back();

    if(dq.empty()){
      cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    return 0;
}