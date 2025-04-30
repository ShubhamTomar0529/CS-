#include<iostream>
#include<string.h>

using namespace std;

class Hero{

    private:
    int health;

    public:
    char level;
    char *name;

    //default constructor
    Hero(){
        cout<<"Simple constructor called"<<endl;
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
        this->health=h;
    }

    void setLevel(char ch){
        this->level=ch;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }

    //copy constructor
    Hero(Hero &temp){
        this->health=temp.health;
        this->level=temp.level;
        name=new char[strlen(temp.name)+1];
        strcpy(this->name,name);
    }

    //printing
    void print(){
        cout<<this->health<<endl;
        cout<<this->level<<endl;
        cout<<this->name<<endl;
    }

};

int main(){

    Hero shubham;
    shubham.setHealth(70);
    shubham.setLevel('A');
    char name[]="shubham";

    shubham.setName(name);
    shubham.print();
    Hero ramesh;

    ramesh=shubham;
    ramesh.print();

    return 0;
}


