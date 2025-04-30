#include<iostream>

using namespace std;

class Hero{

    //cannot be accessed outside the class
    private:
    int health;

    public:
    char level;

    //getter for health
    int getHealth(){
        return health;
    }
    
  
    //setter for health
    void setHealth(int h){
        health=h;
    }

    //getter for level
    char getLevel(){
        return level;
    }

    void setLevel(char ch){
        level=ch;
    }

    void print(){
        cout<<level<<endl;
    }
};

int main(){
    Hero shubham;

    //modifying data members of object shubham
    shubham.level='S';
    shubham.setHealth(1000);

    //accessing date members of object shubham
    cout<<shubham.level<<endl;
    cout<<shubham.getHealth()<<endl;


    return 0;
}