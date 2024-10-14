#include<bits/stdc++.h>
using namespace std;

int partition(string arr[], int low, int high) {
    string Pivot = arr[high];
    int pi = low;
    for (int i = low; i < high; i++) {
        if (arr[i] > Pivot) {
            swap(arr[pi], arr[i]);
            pi++;
        }
    }
    swap(arr[pi], arr[high]);
    return pi;
}

void quickSort(string arr[], int low, int high) {
    if (low >= high) return;
    int Pi = partition(arr, low, high);
    quickSort(arr, low, Pi - 1);
    quickSort(arr, Pi + 1, high);
}

int main() {
    int n;
    cin >> n;
    string *words = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    quickSort(words, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << words[i] << " ";
    }
    delete[] words;
    return 0;
}
