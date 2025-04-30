#include<iostream>

using namespace std;

class Hero{

    private:
    int health;

    public:
    char level;

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
    Hero *ramesh = new Hero;

    //modifying data members of class ramcesh
    (*ramesh).setHealth(1000);
    ramesh->setHealth(1000);
    ramesh->level='S';

    cout<<(*ramesh).level<<endl;
    cout<<ramesh->getHealth()<<endl;

    return 0;
}