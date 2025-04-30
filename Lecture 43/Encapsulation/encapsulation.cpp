#include<iostream>

using namespace std;

class Student{

    private:
    int age;
    int roll;

    public:
    //setters 
    void setAge(int age){
        this->age=age;
    }

    void setRoll(int roll){
        this->roll=roll;
    }

    //getters
    int getAge(){
        return age;
    }

    int getRoll(){
        return roll;
    }

    void print(){
        cout<<this->age<<endl;
        cout<<this->roll<<endl;
    }

};

int main(){

    Student shubham;
    shubham.setAge(18);
    shubham.setRoll(163);

    shubham.print();

    return 0;
}