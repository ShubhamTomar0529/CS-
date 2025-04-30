#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

class MinStack{

    stack<int> s;
    stack<int> mini;
    int min;

    public:
    MinStack(){
        min=INT_MAX;
    }

    void insert(int val){

        if(val < min) min = val;

        s.push(val);
        mini.push(min);
        

    }

    void remove(){

        if(s.size()==0){
            cout<<"Stack underflow"<<endl;
        }

        s.pop();
        mini.pop();

    }

    int top(){

        if(s.size()==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return s.top();

    }

    int getMin(){
        
        if(s.size()==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return mini.top();

    }

};

int main(){

    MinStack s;

    s.insert(-2);
    s.insert(0);
    s.insert(-3);

    cout<<"Min: "<<s.getMin()<<endl;

    s.remove();

    cout<<"Top: "<<s.top()<<endl;
    
    cout<<"Min: "<<s.getMin()<<endl;

    return 0;
}