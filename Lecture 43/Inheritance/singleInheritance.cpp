#include<iostream>

using namespace std;

class Animal{
    public:
    int age;
    int weight;

    void sleep(){
        cout<<"Animal Sleeping"<<endl;
    }

};

class Dog:public Animal{

    public:
    void bark(){
        cout<<"Dog Barking"<<endl;
    }

};

int main(){

    Dog sheru;

    sheru.age=3;
    sheru.weight=15;

    cout<<"Age of dog:"<<sheru.age<<endl;
    cout<<"Weight of dog:"<<sheru.weight<<endl;

    sheru.sleep();
    sheru.bark();

    return 0;
}