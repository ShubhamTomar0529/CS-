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

class Male:protected Human{

    public:
    int getAge(){
        return this->age;
    }

    int getHeight(){
        return this->height;
    } 

};

int main(){

    Male shubham;

    //public data class to protected mode of inheritance->protected data class
    cout<<shubham.getAge()<<endl;

    //protected data class to protected mode of inheritance->protected data class
    cout<<shubham.getHeight()<<endl;

    //private data class to private mode of inheritance->not accessible
    // cout<<shubham.weight()<<endl;
    return 0;   
}