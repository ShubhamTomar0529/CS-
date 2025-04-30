#include<iostream>

using namespace std;

class A{

    public:
    void a(){
        cout<<"Inside function A"<<endl;
    }

};

class B:public A{

    public:
    void b(){
        cout<<"Inside function B"<<endl;
    }

};

class C:public A{

    public:
    void c(){
        cout<<"Inside function C"<<endl;
    }

};

int main(){
    A obja;

    obja.a();

    B objb;

    objb.a();
    objb.b();

    C objc;

    objc.a();
    objc.c();
    
    return 0;
}