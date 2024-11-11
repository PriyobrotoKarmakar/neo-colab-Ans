#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
// You are using GCC
void swap(int *x, int *y) {
    //Type your code here
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

void maxHeapify(int arr[], int n, int i) {
    //Type your code here
    int max = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
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
    for(int i=(n/2)-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    
}

int deleteMax(int arr[], int &n) {
    //Type your code here
    int max = arr[0];
    swap(arr[0],arr[n-1]);
    n--;
    maxHeapify(arr,n,0);
    return max;
}

long long productRemaining(int arr[], int n) {
    //Type your code here
    long long product = 1;
    for(int i=0;i<n;i++){
        product*= arr[i];   
    }
    return product;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);
    int maxElement = deleteMax(arr, n);
    cout << "Deleted largest element: " << maxElement << endl;

    long long product = productRemaining(arr, n);
    cout << "Product of remaining elements: " << product;

    delete[] arr;

    return 0;
}