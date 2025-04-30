#include<iostream>
#include<string.h>

using namespace std;

class hero{
    private:
    int health;
    
    public:

    //static data member
    static int timeToComplete;
    char *name;
    char level;

    //static function
    static int random(){
        return timeToComplete;
    }

    //default constructor
    hero(){
        cout<<"Simple constructor called"<<endl;
        name= new char[100];
    }

    //default destructor
    ~hero(){
        cout<<"Destructor called"<<endl;
    }

    //parametarized constructor
    hero(int health){
        this->health=health;
    }
    hero(int health,int level){
        cout<<"Paramaterized constructor called"<<endl;
        this->health=health;
        this->level=level;
    }

    // copy constructor
    hero(hero& temp){
        cout<<"Copy constructor called"<<endl;
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);

        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;
    }

    //getters
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }


    //setters
    void setHealth(int h){
        health=h;
    }
    void setLevel(char ch){
        level=ch;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }

    //printing
    void print(){
        cout<<"Health: "<<getHealth()<<" ";
        cout<<"Level: "<<getLevel()<<" ";
        cout<<"Name: "<<this->name<<endl;
        cout<<endl;
    }
};

int hero::timeToComplete=5;

int main(){

    cout<<hero::random()<<endl;


    return 0;
}















    // cout<<hero::timeToComplete<<endl;

    // hero a;
    // cout<<a.timeToComplete<<endl;

    // hero b;
    // b.timeToComplete=10;

    // cout<<a.timeToComplete<<endl;
    // cout<<b.timeToComplete<<endl;









    // hero a;

    // hero *b = new hero; 
    // delete b;

    // hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[]="Shubham";
    // hero1.setName(name);

    // hero1.print();

    // hero hero2(hero1);

    // hero2.print();

    // hero1.name[0]='s';
    // hero1.print();

    // hero2.print();
    // return 0;
    // }