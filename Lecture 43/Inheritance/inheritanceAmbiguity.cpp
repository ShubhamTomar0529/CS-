#include<iostream>

using namespace std;

class A{

    public:
    void abc(){
        cout<<"I am A"<<endl;
    }

};

class B{

    public:
    void abc(){
        cout<<"I am B"<<endl;
    }

};

class C:public A,public B{

};

int main(){
    C obj;

    obj.A::abc();
    obj.B::abc();
    
    return 0;
}