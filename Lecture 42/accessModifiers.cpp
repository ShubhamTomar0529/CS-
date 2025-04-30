#include<iostream>

using namespace std;

//creation of class Hero
class Hero{

    //properties
    
    public:
    int health;
    char level;

    void print(){
        cout<<level<<endl;
    }

};

int main(){
    //instantiation of object h1    
    Hero shubham;

    //modifying values of data members of object shubham    
    shubham.health=1000;
    shubham.level='S';

    //accessing data members
    cout<<shubham.health<<endl;
    cout<<shubham.level<<endl;

    return 0;
}