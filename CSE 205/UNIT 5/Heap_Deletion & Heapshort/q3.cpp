#include <iostream>
#include <limits.h>

using namespace std;
// You are using GCC
void swap(int &x, int &y) {
    //Type your code here
    int temp = x;
    x = y;
    y = temp;
}

void maxHeapify(int arr[], int n, int i) {
    //Type your code here
    int max = i;
    int left = max*2 + 1;
    int right = max*2 + 2;
    
    if(left< n and arr[left]>arr[max])
        max = left;
    
    if(right< n and arr[right]>arr[max])
        max = right;
    
    
    if(max != i){
        swap(arr[i],arr[max]);
        maxHeapify(arr,n,max);
    }
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=(n-1)/2;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    
}

void deleteMinFromMaxHeap(int arr[], int &n) {
    //Type your code here
    int minIndex = n/2;
    for(int i=n/2;i<n;i++){
        if(arr[i]<arr[minIndex])
            minIndex = i;
    }
    swap(arr[minIndex],arr[n-1]);
    n--;
}

void printHeap(const int arr[], int n) {
    //Type your code here
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main() {
    int n;
    cin >> n;

    int arr[n];  // Dynamic array based on user input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    printHeap(arr, n);

    deleteMinFromMaxHeap(arr, n);

    printHeap(arr, n);

    return 0;
}