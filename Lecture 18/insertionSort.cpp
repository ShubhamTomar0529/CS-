#include<iostream>

using namespace std;

int main(){

    int arr[]={5,4,3,2,1};
    const int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<=n-1;i++){

        int j = i;
        
        while(arr[j-1]>arr[j] && j>=1){
            
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;

        }

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}