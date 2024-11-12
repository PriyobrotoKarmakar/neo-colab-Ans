// You are using GCC
#include<iostream>
using namespace std;

class ArrayProcessor {
public:
    int* arr;
    int size;

    ArrayProcessor(int n) {
        size = n;
        arr = new int[size];
    }

    void inputArray() {
        for(int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void findDivisibleBy3And5() {
        bool found = false;
        for(int i = 0; i < size; i++) {
            if(arr[i] % 3 == 0 && arr[i] % 5 == 0) {
                if(found) cout << " ";
                cout << arr[i];
                found = true;
            }
        }
        if(!found) cout << "0";
    }

    ~ArrayProcessor() {
        delete[] arr;
    }
};

int main() {
    int N;
    cin >> N;
    ArrayProcessor ap(N);
    ap.inputArray();
    ap.findDivisibleBy3And5();
    return 0;
}

