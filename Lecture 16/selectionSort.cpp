#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){

        int minIdx = i;

        for(int j=i+1;j<n;j++){

            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }

        }
        swap(arr[minIdx],arr[i]);

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}