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

    //search function which searches for the value in the list
    int find(int val){
        for(int i=0;i<size;i++){
            if(list[i]==val) return i;
        }
        return -1;
    }

    //inserting value at index given in the input
    void insertAt(int value,int index){
        for(int i=size;i>index;i--){
            list[i]=list[i-1];       
        }
        list[index]=value;
        size++;
    }

    //removing the value given in the input
    void remove(int value){
        int index=find(value);
        if(index!=-1){
            for(int i=index;i<size;i++){
                list[i]=list[i+1];
            }
            list[size-1]=0;
            size--;
        }
    }

    //replacing value at index given in the input
    void replace(int index,int val){
        list[index]=val;
    }

    //getting size of list
    int getSize(){
        return size;
    }

    //destructor
    ~MyList(){
        delete[] list;
        cout<<"Memory has been successfully deallocated from the heap"<<endl;
    }

};

int main(){

    MyList list;
    list.add(100);
    list.add(200);
    list.add(300);
    list.add(400);
    list.insertAt(500,1);

    list.print();

    list.remove(500);
    list.print();

    cout<<"Size of the List: "<<list.getSize()<<endl;

    list.replace(2,900);
    list.print();

    return 0;
}