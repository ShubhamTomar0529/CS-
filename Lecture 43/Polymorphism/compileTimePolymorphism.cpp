#include<iostream>

using namespace std;

class A{

    public:
    void sayHello(){
        cout<<"Hello Shubham"<<endl;
    }

    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }

    int sayHello(int n){
        cout<<"Hello Shubham"<<endl;
        return n;
    }

    int sayHello(char ch){
        cout<<"Hello "<<ch<<endl;
        return 0;
    }

    int sayHello(int n,char ch){
        cout<<"Hello "<<ch<<endl;
        return n;
    }

};

int main(){

    A obj;

    obj.sayHello();

    string name="Shubham";

    obj.sayHello(name);

    int a=7;
    cout<<obj.sayHello(a)<<endl;


    return 0;
}