#include<iostream>

using namespace std;

class Human{

    public:
    void human(){
        cout<<"I am a human"<<endl;
    }

};

class Male{

    public:
    void male(){
        cout<<"I am a male"<<endl;
    }
};

class Student:public Human,public Male{

};


int main(){

    Student shubham;

    Male ramesh;

    shubham.human();
    shubham.male();

return 0;
}