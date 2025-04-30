#include<iostream>

using namespace std;

class Human{

    public:

    int height;
    int weight;
    
    protected:
    int age;

    private:
    int friends;

    public:
    //setters
    void setHeight(int h){
        this->height=h;
    }

    void setWeight(int w){
        this->weight=w;
    }

    void setAge(int a){
        this->age=a;
    }


    //getters
    int getHeight(){
        return height;
    }

    int getWeight(){
        return weight;
    }

    int getAge(){
        return age;
    }
    int getFriends(){
        return friends;
    }

};

class Male : private Human{
    public:
    string color;

    void sleep(){
        cout<<"Male Sleeping"<<endl;
    }

    int getAge(){
        return this->age;
    }
    //for private base class data member access
    int getFriend(){
        return this->getFriends();
    }
};

int main(){
    Male male1;

    cout<<male1.getAge()<<endl;
    cout<<male1.getFriend()<<endl;
    // cout<<male1.age<<endl;
    // cout<<male1.color<<endl;
    // cout<<male1.height<<endl;
    // cout<<male1.weight<<endl;
    
    // male1.setWeight(60);
    // cout<<male1.weight<<endl;

    //No. of friends are inaccesible 
    // cout<<male1.friends<<endl;

    // male1.sleep();

    return 0;
}