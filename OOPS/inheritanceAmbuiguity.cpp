#include<iostream>
//if we call function xyz in c so which function will get called??
//here we can use scope resolution operator to solve this ambuiguity


using namespace std;

class A{
    public:
    void xyz(){
        cout<<"My name is Shubham"<<endl;
    }
};

class B{
    public:
    void xyz(){
        cout<<"My age is 18"<<endl;
    }
};

class C:public A,public B{
    //multiple inheritance
};

int main(){
    C c1;
    c1.A::xyz();
    c1.B::xyz();
    return 0;
}