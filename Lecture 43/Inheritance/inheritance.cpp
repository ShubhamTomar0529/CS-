#include<iostream>
#include<string.h>

using namespace std;

class Human{

    public:
    int age;
    int weight;
    int height;

    //getters
    int getAge(){
        return age;
    }

    int getWeight(){
        return weight;
    }

    int getHeight(){
        return height;
    }

    //setters
    void setAge(int a){
        this->age=a;
    }

    void setWeight(int w){
        this->weight=w;
    }

    void setHeight(int h){
        this->height=h;
    }

};

class Male:public Human{

    public:
    string color;

    void sleep(){
        cout<<"Male Sleeping"<<endl;
    }

    void setColor(string temp){
        this->color=temp;
    }

};


int main(){
    Male shubham;

    string name="brown";
    shubham.setColor(name);

    shubham.age=18;
    shubham.weight=50;
    shubham.height=180;

    cout<<shubham.getAge()<<endl;
    cout<<shubham.getHeight()<<endl;
    cout<<shubham.getWeight()<<endl;
    cout<<shubham.color<<endl;

    shubham.sleep();
    
    return 0;
}