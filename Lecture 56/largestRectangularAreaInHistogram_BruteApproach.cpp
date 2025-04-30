#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int largestRectangularArea(vector<int> &arr){
    
    int maxArea=0;
    for(int i=0;i<arr.size();i++){

        int length=arr[i];
        int width=1;

        for(int j=i+1;j<arr.size();j++){

            if(arr[i] <= arr[j]){
                width++;
            }
            else{
                break;
            }

        }
        for(int k=i-1;k>=0;k--){

            if(arr[k] >= arr[i]){
                width++;
            }
            else{
                break;
            }

        }
        if(maxArea<length*width) maxArea=length*width;
    }
    return maxArea;
}

int main(){
    int n;
    cout<<"Enter the size of the vector:";
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Maximal Area:"<<largestRectangularArea(arr)<<endl;

    return 0;
}