#include<iostream>
#include<stack>

using namespace std;

int minimumReversal(string &str){

    //odd condition
    if(str.length()%2!=0) return -1;

    stack<char> stack;

    //removing valid part
    for(int i=0;i<str.length();i++){

        char ch=str[i];

        if(ch=='{'){
            stack.push(ch);
        }
        else{

            if(!stack.empty() && stack.top()=='{'){
                stack.pop();
            }
            else{
                stack.push(ch);
            }

        }

    }

    //stack contains all the invalid part
    int a = 0;
    int b = 0;

    while(!stack.empty()){

        if(stack.top()=='{'){
            b++;
        }
        else{
            a++;
        }
        stack.pop();
    }
    
    return ((a+1)/2 + (b+1)/2);

}

int main(){

    string str="{}}}";

    cout<<minimumReversal(str)<<endl;

    return 0;
}