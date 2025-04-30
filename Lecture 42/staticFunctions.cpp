#include<iostream>

using namespace std;

class Hero{


    public:
    int health;
    char level;
    static int timeToComplete;

    Hero(){
        cout<<"Constructor Called:"<<endl;
    }

    ~Hero(){
        cout<<"Destructor called"<<endl;
    }

    static int getTimetoComplete(){
        return timeToComplete;
    }

};

int Hero::timeToComplete=100;


int main(){

    cout<<Hero::getTimetoComplete()<<endl;

    return 0;

}