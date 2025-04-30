#include<iostream>

using namespace std;

class Hero{

    private:
    int health;

    public:
    char level;

    //constructor
    Hero(){
        cout<<"Constructor called"<<endl;
    }

    void print(){
        cout<<health<<endl;
        cout<<level<<endl;
    }

    //setter for health
    void setHealth(int h){
        health=h;
    }

    //getter for health
    int getHealth(){
        return health;
    }

};

int main(){
    //static allocation
    Hero shubham;

    //dynamic allocation
    Hero *ramesh= new Hero;   

    return 0;
}