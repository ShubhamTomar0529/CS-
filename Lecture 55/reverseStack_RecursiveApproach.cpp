#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &stack,int x){

    if(stack.empty()){
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertAtBottom(stack,x);

    stack.push(num);

}
    
void reverse(stack<int> &stack){

    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverse(stack);

    insertAtBottom(stack,num);

}

void print(stack<int> s){

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    print(s);

    reverse(s);

    print(s);

    return 0;
}