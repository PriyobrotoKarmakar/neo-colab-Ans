// You are using GCC
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int n;
    try {
        cin >> n;

        if (n <= 0) {
            if (n == 0) {
                throw runtime_error("Exception caught. Array is empty.");
            } else {
                throw runtime_error("Exception caught. Array size should be a positive number.");
            }
        }

        int* arr = new int[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
