#include<iostream>

using namespace std;

    //Heap is a complete binary tree that comes that comes with a heap order property
    //CBT: Every level is completely filled except the last level(Node always add towards the left)
  
    //max Heap: The value of child will always be smaller than it's parent
    //min Heap: The value of child will always be greater than it's parent

    //If node is the i-th index (according to 1-indexing) then left child 2*i and right child 2*i+1
    //Parent of the i-th node will be at i/2 index(according to 1-indexing)

    /*Steps for insertion:
    1)insert at the end of the array
    2)Take it to the correct position
    */

class Heap{

    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){

        //T.C:- O(logn)

        size++;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }

        }

    }

    void print(){

        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

    void deleteFromHeap(){

        //T.C:- O(logn)

        if(size==0){
            cout<<"Nothing to delete!"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        //take root node to its correct position
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex; 
            }
            else{
                return;
            }
        }
    }

};

//in Complete binary tree leaf node is from (n/2+1) -> n

void heapify(int* arr,int n,int i){

    //T.C.:- O(logn)

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}


int main(){

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"Printing the heapify array:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
} 