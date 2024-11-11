#include <iostream>
using namespace std;
// You are using GCC
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

int main() {
    int size;
    cin >> size;
    if (size < 2) {
        cout << "Array must contain at least two elements";
        return 0;
    }
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    heapSort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The second largest number: " << arr[size - 2];
    delete[] arr;
    return 0;
}