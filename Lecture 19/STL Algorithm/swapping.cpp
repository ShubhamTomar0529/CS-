#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a=3;
    int b=5;
    cout<<"Before swapping:"<<endl;
    cout<<"a:"<<a<<" "<<"b:"<<b<<endl;
    swap(a,b);
    cout<<"After swapping:"<<endl;
    cout<<"a:"<<a<<" "<<"b:"<<b<<endl;
    return 0;
}