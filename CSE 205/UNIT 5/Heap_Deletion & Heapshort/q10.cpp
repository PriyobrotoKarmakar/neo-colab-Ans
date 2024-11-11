#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    //Type your code here
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int size, int root) {
    //Type your code here
    int smallest = root;
    int left = smallest*2 + 1;
    int right = smallest*2 + 2;
    
    if(left<size && arr[left]>arr[smallest])
        smallest = left;
    if(right<size && arr[right]>arr[smallest])
        smallest = right;
    if(smallest!=root){
        swap(arr[smallest],arr[root]);
        heapify(arr,size,smallest);
    }
}

void heapSort(int arr[], int size) {
    //Type your code here 
    for(int i=size/2-1;i>=0;i--)
        heapify(arr,size,i);
    for(int i=size-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
int countGreaterThan(int arr[], int size, int number) {
    //Type your code here
    int count = 0;
    for(int i=size-1;i>=0;i--){
        if(arr[i]>number)count++;
    }
    return count;
    
}
int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    heapSort(arr, size);
    int number;
    cin >> number;
    int greaterCount = countGreaterThan(arr, size, number);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << greaterCount;
    delete[] arr; 
    return 0;
}