#include<iostream>
#include<map>

using namespace std;

int main(){
    map <int,string>m;

    m[1]="Thar";
    m[2]="Scorpio";
    m[3]="Tavera";
    m[13]="Fortuner";

    m.insert({5,"Innova"});
    
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    cout<<"Is 13 present:"<<m.count(13)<<endl;
    cout<<"Is -13 present:"<<m.count(13)<<endl;
    cout<<endl;

    cout<<"After erasing 13:"<<endl;
    m.erase(13);
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    auto it=m.find(5);

    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<" ";
    }
    cout<<endl;

    return 0;
}