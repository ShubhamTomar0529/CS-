#include<iostream>
#include<stack>
#include<limits.h>


using namespace std;

class MinStack{

    stack<int> s;
    int mini;

    public:
    MinStack(){
        mini = INT_MAX;
    }

    void push(int val){

        if(s.empty()){
            s.push(val);
            mini = val;
            return;
        }

        if(val < mini){
            s.push(2*val-mini);
            mini = val;
        }
        else{
            s.push(val);
        }

    }

    int pop(){

        if(s.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        int curr = s.top();
        s.pop();

        if(curr>mini){
            return curr;
        }
        else{
            int prevMini = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMini;
        }

    }

    int top(){

        if(s.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        int curr = s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }

    }

    bool isEmpty(){
        if(s.empty()) return true;
        return false;
    }

    int getMin(){
        if(s.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return mini;
    }

};

int main(){

    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout<<"Min: "<<s.getMin()<<endl;

    cout<<"Element Deleted: "<<s.pop()<<endl;

    cout<<"Top: "<<s.top()<<endl;
    
    cout<<"Min: "<<s.getMin()<<endl;

    return 0;   
}