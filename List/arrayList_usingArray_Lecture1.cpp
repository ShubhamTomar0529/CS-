#include<iostream>

using namespace std;

class MyList{

    private:
    int* list;
    int size;
    const int CAPACITY=5;


    public:
    //constructor
    MyList(){
        list=new int[CAPACITY];
        size=0;
    }

    //adding elements
    void add(int data){
        list[size]=data;
        size++;
    }

    //printing the list
    void print(){
        for(int i=0;i<size;i++){
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }

    //checking if list is empty or not
    bool empty(){
        return size==0;
    }

    //checking if list overflows 
    bool full(){
        return size==CAPACITY;
    }

};

int main(){

    MyList list;

    cout<<"Empty: "<<boolalpha<<list.empty()<<endl;
    cout<<endl;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.print();
    cout<<endl;

    cout<<"Full: "<<boolalpha<<list.full()<<endl;


    return 0;
}