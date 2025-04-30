#include<iostream>
#include<stack>

using namespace std;

int main(){

    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    //top
    cout<<"Printing top element:"<<s.top()<<endl;

    //empty checking
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    //size of the stack
    cout<<"Size:"<<s.size()<<endl;

    return 0;
}