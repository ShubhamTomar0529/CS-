#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s){

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void sortedInsert(stack<int> &s,int num){

    if(s.empty() || num > s.top()){
        s.push(num);
        return;
    }

    int x = s.top();
    s.pop();

    sortedInsert(s,num);

    s.push(x);

}

void sortStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s,num);

}

int main(){
    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    print(s);

    sortStack(s);

    print(s);


    return 0;
}