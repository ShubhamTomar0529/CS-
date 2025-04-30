//poly means many
//morphism meand forms
//polymorphism means existing in multiple forms


//two types of polymorphism:- 1)compile time 2)run time
//1)compile time:- 1)function overloadig 2)operator overloading
#include<iostream>

using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello Shubham Tomar"<<endl;
    }

    void sayHello(int n){
        cout<<"Hello"<<n<<endl;
    }

    // int sayHello(){
    //     return 1;
    // }

    void sayHello(string name){
        cout<<"Hello"<<name<<endl;
    }

};


int main(){
    A a1;
    a1.sayHello();

    return 0;
}