#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

class MinStack{

    stack<long long int> s;
    long long int mini;

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
            s.push(2LL*val - mini);
            mini = val;
        }
        else{
            s.push(val);
        }

    }

    void pop() {

        long long int curr = s.top();
        s.pop();

        if(curr<mini){
            mini = 2LL*mini - curr;
        }

    }
    
    int top() {
        
        long long int curr = s.top();

        if(curr > mini){
            return s.top();
        }
        else{
            return mini;
        }

    }
    
    int getMin() {
        return mini;
    }
};

int main(){

    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout<<"Min: "<<s.getMin()<<endl;

    s.pop();

    cout<<"Top: "<<s.top()<<endl;
    
    cout<<"Min: "<<s.getMin()<<endl;

    return 0;
}