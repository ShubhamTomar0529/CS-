//A->B->C
#include<iostream>

using namespace std;

class Animal{

    public:
    int weight; 
    int age;


    void speak(){
        cout<<"Speaking" <<endl;
    }
};


class Dog:public Animal{


};

class GermanShepherd:public Dog{


};


int main(){

    GermanShepherd g;
    g.speak();
    return 0;   
}