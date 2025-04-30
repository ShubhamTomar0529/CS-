#include<iostream>
#include<string.h>

using namespace std;

class Hero{

    private:
    int health;

    public:
    char *name;
    char level;

    //default constructor
    Hero(){
        cout<<"Constructor called"<<endl;
        name=new char[100];
    }

    //getters
    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    //setters
    void setHealth(int h){
        health=h;
    }

    void setLevel(char ch){
        level=ch;
    }

    void print(){
        cout<<this->health<<endl;
        cout<<this->level<<endl;
        cout<<this->name<<endl;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }


};

int main(){
    //user defined constructor called
    Hero shubham;
    shubham.setHealth(70);
    shubham.setLevel('A');

    char name[]="shubham";

    shubham.setName(name);

    shubham.print();

    //default copy constructor called
    Hero ramesh(shubham);

    ramesh.print();

    shubham.name[0]='b';

    shubham.print();

    ramesh.print();

    return 0;
}