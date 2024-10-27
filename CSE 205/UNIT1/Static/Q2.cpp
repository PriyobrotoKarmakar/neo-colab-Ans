// You are using GCC
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    //Type your code here
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    //Type your code here
    int start = 0;
    int end = n-1;
    
    while(start<=end){
        int mid = (end-(end-start)/2);
        if(arr[mid]==key){
            return mid;
        }
        else if(key<arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int searchArray(int arr[], int n, int key) {
    if (isSorted(arr, n)) {
        cout << "Using Binary Search" << endl;
        return binarySearch(arr, n, key);
    } else {
        cout << "Using Linear Search" << endl;
        return linearSearch(arr, n, key);
    }
}

int main() {
    int n, key;
    cin >> n;
    
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    cin >> key;

    int result = searchArray(arr, n, key);

    if (result != -1) {
        cout << key << " found at index " << result;
    } else {
        cout << key << " not found in the list";
    }

    return 0;
}