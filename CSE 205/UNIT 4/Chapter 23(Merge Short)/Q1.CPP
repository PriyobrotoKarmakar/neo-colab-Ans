#include <iostream>
#include <iomanip>
using namespace std;

void merge(float *arr, int s, int m, int e) {
    int L = m - s + 1;
    int R = e - m;
    float v1[L], v2[R];
    int index = s;
    
    for (int i = 0; i < L; i++) {
        v1[i] = arr[index++];
    }
    for (int i = 0; i < R; i++) {
        v2[i] = arr[index++];
    }
    
    int i = 0, j = 0;
    index = s;
    
    while (i < L && j < R) {
        if (v1[i] > v2[j]) {
            arr[index++] = v1[i++];
        } else {
            arr[index++] = v2[j++];
        }
    }
    
    while (i < L) {
        arr[index++] = v1[i++];
    }
    
    while (j < R) {
        arr[index++] = v2[j++];
    }
}

void mergeSort(float *arr, int s, int e) {
    if (s >= e) return;
    
    int m = s + (e - s) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m + 1, e);
    merge(arr, s, m, e);
}

int main() {
    int n;
    cin >> n;
    
    float arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
