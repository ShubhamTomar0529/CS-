#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string str="abcd";

    cout<<"Before reversing:";
    cout<<str<<endl;

    reverse(str.begin(),str.end());

    cout<<"After reversing:";
    cout<<str<<endl;

    return 0;
}