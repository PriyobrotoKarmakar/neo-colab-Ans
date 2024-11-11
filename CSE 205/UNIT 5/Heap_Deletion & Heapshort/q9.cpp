#include <iostream>
#include <cstring>
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
    
    if(left<size && arr[left]<arr[smallest])
        smallest = left;
    if(right<size && arr[right]<arr[smallest])
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

int getRainfallForMonth(const int rainfall[], const char* monthNames[], int size, const char* month) {
    //Type your code here
    for (int i = 0; i < size; i++) {
        if (strcmp(monthNames[i], month) == 0) {
            return rainfall[i];
        }
    }
    return -1;
}
int main() {
    const int MONTHS = 12;
    int rainfall[MONTHS];
    const char* monthNames[MONTHS] = {
        "January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", 
        "November", "December"
    };
    for (int i = 0; i < MONTHS; i++) {
        cin >> rainfall[i];
    }
    heapSort(rainfall, MONTHS);
    for (int i = 0; i < MONTHS; i++) {
        cout << rainfall[i] << " ";
    }
    cout << endl;
    char month[20];
    cin >> month;
    int rainfallAmount = getRainfallForMonth(rainfall, monthNames, MONTHS, month);
    if (rainfallAmount != -1) {
        cout << "Rainfall in " << month << ": " << rainfallAmount;
    } else {
        cout << "Month not found";
    }
    return 0;
}