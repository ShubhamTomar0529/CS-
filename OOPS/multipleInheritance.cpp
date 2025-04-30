//one class A,another class B, class C inheritates both A and B class
#include<iostream>

using namespace std;

class A{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }

};

class B{
    public:
    void bark(){
        cout<<"Barking"<<endl;
    }

};

class C:public A,public B{


};

int main(){

    C c1;
    c1.bark();
    c1.speak();
    return 0;
}