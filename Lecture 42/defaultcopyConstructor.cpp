#include<iostream>

using namespace std;

class Hero{

    public:
    int health;
    char level;

    void print(){
        cout<<"health:"<<health<<endl;
        cout<<"level:"<<level<<endl;
    }

    Hero(){
        cout<<"Simple Constructor Called"<<endl;
        
    }

};

int main(){

    Hero shubham;

    shubham.health=1000;
    shubham.level='S';

    shubham.print();

    Hero ramesh(shubham);

    ramesh.print();

    shubham.health=100;
    
    shubham.print();

    ramesh.print();

    return 0;
}