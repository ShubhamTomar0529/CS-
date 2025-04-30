#include<iostream>

using namespace std;

class NStack{

private:
    int* arr;
    int* next;
    int* top;
    int freeSpot;
    int n;
    int s;

public:
    NStack(int N,int S){
        n = N;
        s = N;
        arr = new int[n];
        top = new int[s];
        next = new int[n];

        //initialize top
        for(int i=0;i<s;i++){
            top[i] = -1;
        }

        //initialize next
        for(int i=0;i<n;i++){
            next[i] = i+1;
        }

        freeSpot=0;
    }

    bool push(int x,int m){
        //check for overflow
        if(freeSpot==-1){
            return false;
        }

        //find index
        int index = freeSpot;
        
        //update freeSpot
        freeSpot = next[index];

        //insert in array
        arr[index] = x;

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;


    }

    int pop(int m){
        
        if(top[m-1]==-1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }

    int peek(int m){

        if(top[m-1]==-1){
            return -1;
        }

        return arr[top[m-1]];

    }


};

int main(){

    NStack stack(6,3);

    stack.push(10,1);
    stack.push(20,1);

    cout<<"Element Deleted: "<<stack.pop(1)<<endl;

    cout<<"Top: "<<stack.peek(1)<<endl;;

    return 0;
}