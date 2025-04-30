#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s,int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s,x);

    s.push(num);

}

void print(stack<int> s){

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;

}

int main(){
    
    stack<int> s;

    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    print(s);

    int x;
    cout<<"Enter the number you want to insert at bottom of the given stack:";
    cin>>x;

    insertAtBottom(s,x);

    print(s);

    return 0;
}