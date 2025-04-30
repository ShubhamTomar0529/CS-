#include<iostream>
//if a class is parent for more than one class 
//for ex if class A is parent to class B and class C
using namespace std;

class A{
    public:

    void a(){
        cout<<"I am function a"<<endl;
    }
};

class B:public A{
    public:
    //subclass of A
    void b(){
        cout<<"I am function b"<<endl;
    }
};

class C:public A{
    public:
    //subclass of A
    void c(){
        cout<<"I am function c"<<endl;
    }
};


int main(){
    A a1;
    B b1;
    C c1;
    a1.a();
    b1.a();
    b1.b();
    c1.a();
    c1.c();
    return 0;
}