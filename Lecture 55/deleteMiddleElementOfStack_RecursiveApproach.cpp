#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int>&s,int count,int size){

    if(count==size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    solve(s,count+1,size);

    s.push(num);

}

void deleteMid(stack<int> &s){

    int count=0;

    solve(s,count,s.size());
 
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

    deleteMid(s);

    print(s);

    return 0;
}