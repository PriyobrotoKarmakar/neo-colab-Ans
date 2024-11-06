#include <iostream>
using namespace std;
// You are using GCC
void swap( int &a, int &b) {
    //Type your code here
    int temp = a;
    a = b;
    b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    //Type your code here
    int max = i;
    int left = max*2+1;
    int right = max*2+2;
    if(left<n && arr[left]>arr[max]){
        max = left;
    }
    if(right<n && arr[right]>arr[max]){
        max = right;
    }
    
    if(max!=i){
        swap(arr[max],arr[i]);
        maxHeapify(arr,n,max);
    }
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
    // for(int i=n;i>=0;i--){
    //     maxHeapify(arr,n,i);
    // }
    return;
}

void insertIntoMaxHeap(int arr[], int &n, int value) {
    //Type your code here
    arr[n] = value;
    n++;
    int i = n-1;
    while(i>0){
        int child = i;
        int parent = (child-1)/2;
        if(arr[parent]<arr[child]){
            swap(arr[parent],arr[child]);
            i = parent;
        }else{
            break;
        }
    }
}

void printMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, n, value);
    }
    buildMaxHeap(arr, n);
    printMaxHeap(arr, n);
    if (n > 0) {
        int sum = arr[0] + arr[n - 1]; 
        cout << sum;
    } else {
        cout << "Heap is empty";
    }
    return 0;
}