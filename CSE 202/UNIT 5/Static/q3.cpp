// You are using GCC
#include<iostream>
using namespace std;

class PalindromeChecker {
public:
    int* arr;
    int size;

    PalindromeChecker(int n) {
        size = n;
        arr = new int[size];
    }

    void inputArray() {
        for(int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    bool isPalindrome(int num) {
        int original = num, reversed = 0;
        while(num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return original == reversed;
    }

    void findPalindromes() {
        bool found = false;
        for(int i = 0; i < size; i++) {
            if(isPalindrome(arr[i])) {
                if(found) cout << " ";
                cout << arr[i];
                found = true;
            }
        }
    }

    ~PalindromeChecker() {
        delete[] arr;
    }
};

int main() {
    int N;
    cin >> N;
    PalindromeChecker pc(N);
    pc.inputArray();
    pc.findPalindromes();
    return 0;
}
