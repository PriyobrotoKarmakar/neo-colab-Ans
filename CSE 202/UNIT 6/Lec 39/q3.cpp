#include <iostream>
#include <algorithm>  // For std::max
using namespace std;

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template <typename T>
Array<T>::Array(T array[], int s) {
    T largest1 = array[0];
    T largest2 = array[1];
    
    // Ensure largest1 is the largest and largest2 is the second largest
    if (largest1 < largest2) {
        swap(largest1, largest2);
    }
    
    for (int i = 2; i < s; i++) {
        if (array[i] > largest1) {
            largest2 = largest1;  // The previous largest becomes the second largest
            largest1 = array[i];  // Update the largest
        } else if (array[i] > largest2) {
            largest2 = array[i];  // Update the second largest
        }
    }
    
    cout << largest1 << " " << largest2 << endl;
}

int main() {
    int n;
    cin >> n;
    
    int ar[n];
    float br[n];
    
    // Input for integer array
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    
    // Input for floating-point array
    for (int i = 0; i < n; i++) {
        cin >> br[i];
    }
    
    // Create Array objects for integer and float arrays
    Array<int> a(ar, n);
    Array<float> b(br, n);
    
    return 0;
}
