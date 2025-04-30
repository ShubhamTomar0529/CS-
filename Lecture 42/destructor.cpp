#include<iostream>
#include<string.h>

using namespace std;

class Hero{

    public:
    int health;
    char level;
    char *name;

    Hero(){
        cout<<"Constructor called"<<endl;
        name=new char[100];
    }

    ~Hero(){
        cout<<"Destructor called ";
        cout<<this->name<<endl;
    }

};

int main(){
    //static 
    Hero shubham;
    strcpy(shubham.name,"Shubham");
    //dynamic
    Hero *ramesh=new Hero;
    strcpy(ramesh->name,"ramesh");
    delete ramesh;
    return 0;
}