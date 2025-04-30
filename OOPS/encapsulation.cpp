#include<iostream>
#include<string.h>


using namespace std;

//wrapping up data members and function

//fully encapsulated class: each data member is private

//advantage of encapsulation:-
//1)data hidden(secure data)
//2)we can make the data read only by only adding getters in the class and not the setters.
//3)code reusability 


class student{
    private:
    int rollNum;
    int age;

    public:

    int getRoll(){
        return rollNum;
    }

    int getAge(){
        return age;
    }

    void setData(int roll,int age){
        this->age=age;
        this->rollNum=roll;
    }  

    void print(){
        cout<<"Age of student is:"<<this->age<<endl;
        cout<<"Roll no of student is:"<<this->rollNum<<endl;
    }

};

int main(){

    student shubham;

    shubham.setData(163,18);

    shubham.print();

    return 0;
}