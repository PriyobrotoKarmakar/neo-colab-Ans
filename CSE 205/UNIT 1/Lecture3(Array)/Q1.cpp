#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char arr[MAX_SIZE];
    int size;
    int pos;
    char newChar;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cin >> pos;
    cin >> newChar;

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = newChar;
    size++;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}