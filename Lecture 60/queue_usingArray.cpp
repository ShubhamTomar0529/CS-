#include<iostream>

using namespace std;

class Queue {

    int* arr;
    int forward;
    int rear;
    int size;

public:

    Queue() {
        forward= 0;
        rear = 0;
        size = 5000;
        arr = new int[size];
    }

    bool isEmpty() {

        return (forward==rear);

    }

    void enqueue(int data) {
        
        if(rear == size){
            cout<<"Queue overflow"<<endl;   //queue is full
        }
        else{
            arr[rear] = data;
            rear++;
        }

    }

    int dequeue() {
        
        if(forward == rear){
            cout<<"Queue Underflow"<<endl;
            return -1; //queue is empty
        }
        else{
            int val = arr[forward];
            arr[forward] = -1;
            forward++;

            if(forward== rear){
                forward = rear = 0;
            }

            return val;

        }

    }

    int front() {
        
        if(forward == rear){
            return -1;
        }
        else{
            return arr[forward];
        }

    }
};

int main(){

    Queue q;

    q.enqueue(5);
    q.enqueue(7);

    cout<<"Front of queue is: "<<q.front()<<endl;

    q.dequeue();

    cout<<"Front of queue is: "<<q.front()<<endl;

    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    return 0;
}