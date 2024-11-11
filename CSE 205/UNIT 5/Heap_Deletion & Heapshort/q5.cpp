#include <iostream>
#include <iomanip> 

using namespace std;
// You are using GCC
void swap(int *x, int *y) {
    //Type your code here
    int temp = *x;
    *x = *y;
    *y = temp;
    
}
void minHeapify(int arr[], int n, int i) {
    //Type your code here
    int mini = i;
    int left = i*2+1;
    int right = i*2 + 2;
    
    if(left<n && arr[left]<arr[mini])
        mini = left;
    if(right<n && arr[right]<arr[mini])
        mini = right;
        
    if(mini!=i){
        swap(&arr[mini],&arr[i]);
        minHeapify(arr,n,mini);
    }
}
void buildMinHeap(int arr[], int n) {
    //Type your code here
    for(int i = (n / 2) - 1;i>=0;i--){
        minHeapify(arr,n,i);
    }
}
int filterElements(int arr[], int *n, double avg) {
    //Type your code here
    int newsize = 0;
    // int ans[*n];
    for(int i=0;i<*n;i++){
        if(arr[i]>avg){
            arr[newsize] = arr[i];
            newsize++;
        }
    }

    *n = newsize;
    buildMinHeap(arr,*n);
    return *n;
}
double calculateAverage(int arr[], int n) {
    //Type your code here
    double avg = 0;
    for(int i=0;i<n;i++){
        avg+=arr[i];
    }
    return (avg/n);
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMinHeap(arr, n);

    double avg = calculateAverage(arr, n);

    n = filterElements(arr, &n, avg);

    cout << "Average: " << fixed << setprecision(2) << avg << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}