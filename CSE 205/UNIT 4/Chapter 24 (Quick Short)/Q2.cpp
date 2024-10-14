#include<bits/stdc++.h>
using namespace std;

int partition(string names[], int heights[], int low, int high) {
    int pivot = heights[high];
    int pi = low;
    for (int i = low; i < high; i++) {
        if (heights[i] > pivot) {
            swap(heights[pi], heights[i]);
            swap(names[pi], names[i]);
            pi++;
        }
    }
    swap(heights[pi], heights[high]);
    swap(names[pi], names[high]);
    return pi;
}

void quickSort(string names[], int heights[], int low, int high) {
    if (low >= high) return;
    int pi = partition(names, heights, low, high);
    quickSort(names, heights, low, pi - 1);
    quickSort(names, heights, pi + 1, high);
}

int main() {
    int n;
    cin >> n;
    string *names = new string[n];
    int *heights = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> heights[i];
    }
    quickSort(names, heights, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }
    delete[] names;
    return 0;
}
