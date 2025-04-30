#include<iostream>

using namespace std;

class Hero{

    public:
    int health;
    char level;
    
    //copy constructor
    Hero(Hero &temp){
        cout<<"Copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }

    //printing
    void print(){
        cout<<this->health<<endl;  
        cout<<this->level<<endl;
    }

    //constructor
    Hero(){
        cout<<"Constructor called"<<endl;
    }

    

};

int main(){
    Hero shubham;

    shubham.health=1000;
    shubham.level='A';

    shubham.print();

    Hero ramesh(shubham);
    ramesh.print();

    shubham.health=100;

    shubham.print();

    ramesh.print();

    return 0;
}