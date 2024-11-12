// You are using GCC
#include <iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int arr[], int n, int i)
{
    //Type your code here
    int min = i;
   int left =i*2 + 1;
   int right = i*2 + 2;
   if(left<n && arr[left]<arr[min]){
       min = left;
   }
   if(right<n && arr[right]<arr[min]){
       min = right;
   }
   if(min!=i){
       swap(arr[i],arr[min]);
       minHeapify(arr,n,min);
   }
}

void buildMaxHeap(int arr[], int n) 
{
   //Type your code here
   for(int i= n/2 - 1;i>=0;i--)
        minHeapify(arr,n,i);
}
void insertElement(int heap[], int &size, int value, int capacity) 
{
    //Type your code here
    if(size>=capacity){
        return;
    }
    heap[size] = value;
    size++;
    
    buildMaxHeap(heap,size);
    
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int findMaxValue(int arr[], int size)
{
    //Type your code here
    int max = INT_MIN;
    for(int i=0;i<size;i++){
        max = max<arr[i] ? arr[i] : max;
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int capacity = n; 
    int heap[capacity]; 
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, capacity);
    }

    displayMinHeap(heap, size);

    int maxValue = findMaxValue(heap, size);
    cout << "Maximum: " << maxValue;

    return 0;
}
