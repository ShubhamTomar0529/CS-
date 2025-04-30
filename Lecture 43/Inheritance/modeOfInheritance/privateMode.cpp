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

class Male:private Human{
    public:
    int getAge(){
        return this->age;
    }

    int getHeight(){
        return this->height;
    }

    // int getWeight(){
    //     return this->weight;
    // }

};

int main(){

    Male shubham;

    cout<<shubham.getAge()<<endl;
    cout<<shubham.getHeight()<<endl;
    //private data class to private mode of inheritance is not accessible 
    // cout<<shubham.weight<<endl;
    
    return 0;  
}