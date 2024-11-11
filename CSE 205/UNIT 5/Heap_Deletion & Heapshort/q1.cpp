#include <iostream>
using namespace std;

// You are using GCC
void swap(int &a, int &b) {
    //Type your code here
    int temp = a;
    a = b;
    b = temp;
    
}

void maxHeapify(int arr[], int n, int i) {
    //Type your code here
    int small = i;
    int left = small*2+1;
    int right = small*2 +2;
    
    if(left<n and arr[left]>arr[small])
        small = left;
    
    if(right<n and arr[right]>arr[small])
        small = right;
        
    if(small!=i){
        swap(arr[small],arr[i]);
        maxHeapify(arr,n,small);
    }
    
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=n-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}

void deleteGreaterThanThreshold(int arr[], int &n, int threshold) {
    //Type your code here
    int index = 0;
    while(index<n){
        if(arr[index]>threshold){
            swap(arr[index],arr[n-1]);
            n--;
            maxHeapify(arr,n,index);
        }else{
            index++;
        }
    }
    
}

void printMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[100];
    int n;
    int threshold;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> threshold;

    buildMaxHeap(arr, n);

    deleteGreaterThanThreshold(arr, n, threshold);

    printMaxHeap(arr, n);

    return 0;
}