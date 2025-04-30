#include<iostream>

using namespace std;

class Hero{

    private:
    int health;

    public:
    char level;

    //parameterized constructor
    Hero(int health,char level){
        this->health=health;
        this->level=level;   
    }

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
    Hero shubham(1000,'A');


    cout<<shubham.getHealth()<<endl;
    cout<<shubham.level<<endl;

    return 0;
}