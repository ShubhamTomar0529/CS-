#include<iostream>

using namespace std;

class Stack{

    //properties
    public:
    int* arr;
    int top;
    int size;
    

    //behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    //push function
    void push(int element){

        if(size - top > 1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }

    }

    //pop function
    void pop(){

        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }

    }

    //top function
    int peek(){

        if(top>=0){
        return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        } 

    }

    //empty function
    bool empty(){

        if(top==-1) return true;
        return false;

    }

    int getSize(){

        if(top==-1) return 0;
        return (top+1);

    }

};

int main(){

    Stack s(5);

    s.push(22);
    s.push(43);
    s.push(44);
    s.push(22);
    s.push(43);

    cout<<s.peek()<<endl;

    s.pop();

    cout<<s.peek()<<endl;

    if(s.empty()){
        cout<<"Stack is empty mere dost"<<endl;
    }
    else{
        cout<<"Stack is not empty mere dost"<<endl;
    }

    return 0;
}