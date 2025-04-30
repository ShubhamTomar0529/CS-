#include<iostream>

using namespace std;

class Animal{

    public:

    void speak(){
        cout<<"Speaking"<<endl;
    }

};

class Dog:public Animal{

    public:
    void speak(){
        cout<<"Barking"<<endl;
    }

};

int main(){

    Dog sheru;

    sheru.speak();

    return 0;
}