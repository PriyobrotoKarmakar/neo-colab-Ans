// You are using GCC
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

bool isNearlySorted(int scores[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (scores[i] > scores[i + 1]) {
            count++;
            if (count > 1) { 
                return false;
            }
        }
    }
    return true;
}

void sortArray(int scores[], int n) {
    if (isNearlySorted(scores, n)) {
        cout << "Using Bubble Sort" << endl;
        bubbleSort(scores, n);
    } else {
        cout << "Using Selection Sort" << endl;
        selectionSort(scores, n);
    }
}

void printArray(int scores[], int n) {
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int examScores[n];
    for (int i = 0; i < n; i++) {
        cin >> examScores[i];
    }

    sortArray(examScores, n);

    cout << "Sorted Exam Scores: ";
    printArray(examScores, n);

    return 0;
}