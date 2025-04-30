#include<iostream>
#include<stack>

using namespace std;

class MyQueue {

    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
        s1.push(x);

    }
    
    int pop() {
        
        if(s1.empty()) return -1;

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int popped = s2.top();
        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return popped;
    }
    
    int peek() {
        
        if(s1.empty()) return -1;

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int top = s2.top();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return top;
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};

int main(){

    return 0;
}