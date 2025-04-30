#include<iostream>

using namespace std;

class TwoStack{

    int* arr;

    int top1;
    int top2;

    int size;

    public:

    TwoStack(int size){
        this->size=size;
        top1=-1;
        top2=size;
        arr=new int[size];
    }

    void push1(int num){

        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
        else{
            cout<<"Stack if full"<<endl;
        }

    }

    void push2(int num){

        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
        else{
            cout<<"Stack is full"<<endl;
        }

    }

    int pop1(){

        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }

    }

    int pop2(){

        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }

    }

    void print(){

        cout<<"Stack1: ";
        for(int i=0;i<=top1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        cout<<"Stack2: ";
        for(int i=top2;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

};

int main(){

    TwoStack s(5);

    s.push1(0);
    s.push2(4);
    s.push1(1);

    s.pop1();

    s.print();

    return 0;    
}