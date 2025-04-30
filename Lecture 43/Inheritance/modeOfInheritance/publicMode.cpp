#include<iostream>

using namespace std;

class Human{

    public:
    int age;

    protected:
    int height;

    private:
    int weight;


};

class Male:public Human{

    public:
    int getHeight(){
        return this->height;
    }


};

int main(){
    Male shubham;
    //public base class to public mode of inheritance->public data member
    cout<<shubham.age<<endl;

    //protected base class to public mode of inheritance->protected data member
    cout<<shubham.getHeight()<<endl;

    //private base class to public mode of inheritance->not accessible
    // cout<<shubham.weight()<<endl;

    return 0;
}