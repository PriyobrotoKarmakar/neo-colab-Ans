// You are using GCC
#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    //Type your code here
    int temp   = x;
    x = y;
    y = temp;
}
void minHeapify(int arr[], int size, int i) {
    //Type your code here
    int sm = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<size && arr[left]<arr[sm]){
        sm = left;
    }
    if(right<size && arr[right]<arr[sm]){
        sm = right;
    }
    
    if(sm!=i){
        swap(arr[i],arr[sm]);
        minHeapify(arr,size,sm);
    }
    
    
}
void buildMinHeap(int heap[], int size) {
    //Type your code here
    // for(int i= size/2-1;i>=0;i--){
    //     minHeapify(heap,size,i);
    // }
    return;
}
void insertElement(int heap[], int &size, int val, int &sumEven, int &sumOdd) {
    //Type your code here
    heap[size] = val;
    size++;
    if((val%2)==0){
        sumEven+=val;
    }else{
        sumOdd+=val;
    }
    int i = size-1;
    while(i>0){
        int child = i;
        int parent = (child-1)/2;
        if(heap[parent]>heap[child]){
            swap(heap[parent],heap[child]);
            i = parent;
        }else{
            break;
        }
    }
}
void displayMinHeap(int heap[], int size) {
    //Type your code here
    for(int i=0;i<size;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;
    int heap[n];
    int size = 0;
    int sumEven = 0, sumOdd = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, sumEven, sumOdd);
    }
    buildMinHeap(heap, size);
    cout << "Min Heap: ";
    displayMinHeap(heap, size);
    cout << "Sum of even elements: " << sumEven << endl;
    cout << "Sum of odd elements: " << sumOdd;
    return 0;
}