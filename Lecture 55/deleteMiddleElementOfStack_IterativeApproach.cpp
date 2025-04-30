#include<iostream>
#include<stack>

using namespace std;

void deleteMid(stack<int> &s,int N){

    int middleIndex=N/2;
    stack<int> temp;

    for(int i=0;i<middleIndex;i++){
        temp.push(s.top());
        s.pop();
    }

    s.pop();

    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }

}

void print(stack<int> s){

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}

int main(){
    stack<int> s;

    s.push(3);
    s.push(5);
    s.push(9);
    s.push(2);
    s.push(4);

    deleteMid(s,s.size());

    print(s);

    return 0;
}
