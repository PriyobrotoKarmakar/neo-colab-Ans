// You are using GCC
#include <bits/stdc++.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxHeapify(int arr[], int n, int i) 
{
   //Type your code here
   int maxi = i;
   int left =i*2 + 1;
   int right = i*2 +2;
   if(left<n && arr[left]>arr[maxi]){
       maxi = left;
   }
   if(right<n && arr[right]>arr[maxi]){
       maxi = right;
   }
   if(maxi!=i){
       swap(arr,i,maxi);
       maxHeapify(arr,n,maxi);
   }
}

void buildMaxHeap(int arr[], int n) 
{
   //Type your code here
   for(int i= n/2 - 1;i>=0;i--)
        maxHeapify(arr,n,i);
}

void insertIntoMaxHeap(int arr[], int &n, int value) 
{
    //Type your code here
    arr[n] =value;
    n++;
    buildMaxHeap(arr,n);
}

int isPrime(int num) 
{
    //Type your code here
    if(num==1)return 0;
    for(int i=2;i<num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
    
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[100];
    int n = 0; 
    int num_elements;

    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        int value;
        scanf("%d", &value);

        if (isPrime(value)) {
            insertIntoMaxHeap(arr, n, value);
        } else {
            printf("%d is not a prime number\n", value);
        }
    }

    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printMaxHeap(arr, n);

    return 0;
}