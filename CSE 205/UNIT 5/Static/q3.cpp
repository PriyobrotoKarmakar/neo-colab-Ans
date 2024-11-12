#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    void minHeapify(int arr[], int size, int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;
        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            minHeapify(arr, size, smallest);
        }
    }
    
    void buildMinHeap(int arr[], int size) {
        for (int i = size / 2 - 1; i >= 0; --i) {
            minHeapify(arr, size, i);
        }
    }
    
    void deleteRoot(int arr[], int& size) {
        swap(arr[0], arr[size - 1]);
        --size;
        minHeapify(arr, size, 0);
    }
    
    void displayHeap(int arr[], int size) const {
        cout << "Min Heap: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void displayMaxValue(int arr[], int size) const {
        int maxVal = *max_element(arr, arr + size);
        cout << "Maximum value: " << maxVal << endl;
    }
    
    void displaySumAndAverage(int arr[], int size) const {
        int total = accumulate(arr, arr + size, 0);
        cout << "Sum of nodes: " << total << endl;
        printf("Average of nodes: %.2f\n", static_cast<float>(total) / size);
    }
};

int main() {
    Heap heap;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
        heap.buildMinHeap(arr, i + 1);
    }
    heap.displayHeap(arr, size);
    cout << "Root node: " << arr[0] << endl;
    heap.deleteRoot(arr, size);
    heap.displayMaxValue(arr, size);
    heap.displaySumAndAverage(arr, size);
    
    return 0;
}
