#include<iostream>

using namespace std;

void mergeSort(int *arr,int s,int e){

    
}

int main(){

    int arr[]={2,5,1,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}