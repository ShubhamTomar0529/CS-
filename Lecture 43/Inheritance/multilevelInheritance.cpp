#include<iostream>

using namespace std;

class Animal{
    public:

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    void eat(){
        cout<<"Eating"<<endl;
    }

};

class Dog:public Animal{

    public:
    void bark(){
        cout<<"Barking"<<endl;
    }

};

class GermanShepherd:public Dog{

};


int main(){

    GermanShepherd sheru;

    sheru.sleep();
    sheru.bark();
    sheru.eat();

    return 0;
}