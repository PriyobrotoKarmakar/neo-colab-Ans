#include <iostream>
using namespace std;
// You are using GCC
void swap(char &a, char &b) {
    //Type your code here
    char temp = a;
    a = b;
    b= temp;
}

void heapify(char arr[], int size, int root) {
    //Type your code here
    int child = root;
    int left = child*2 + 1;
    int right = child*2 + 2;
    
    if(left<size && arr[left]>arr[child])
        child = left;
    if(right<size && arr[right]>arr[child])
        child = right;
        
    if(child!=root){
        swap(arr[child],arr[root]);
        heapify(arr,size,child);
    }
}

void heapSort(char arr[], int size) {
    //Type your code here
    for(int i = (size/2)-1;i>=0;i--){
        heapify(arr,size,i);
    }
    for(int i=size-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main() {
    int size;
    cin >> size;
    char arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heapSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}