#include<iostream>

using namespace std;

class Hero{

    public:
    static int timeToComplete;

    Hero(){
        cout<<"Constructor called"<<endl;
    }

    ~Hero(){
        cout<<"Destructor called"<<endl;
    }

};

int Hero::timeToComplete=100;

int main(){

    cout<<Hero::timeToComplete<<endl;

    Hero a;

    cout<<a.timeToComplete<<endl;

    Hero b;

    cout<<b.timeToComplete<<endl;

    a.timeToComplete=10;

    cout<<a.timeToComplete<<endl;
    cout<<b.timeToComplete<<endl;

    return 0; 
}