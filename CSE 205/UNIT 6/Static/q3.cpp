#include <iostream>
#include <vector>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

void quadraticProbing(const vector<int> &elements, int tableSize) {
    vector<int> hashTable(tableSize, -1);

    for (int elem : elements) {
        int hashIndex = hashFunction(elem, tableSize);
        int i = 0;
        while (i < tableSize) {
            int newIndex = (hashIndex + i * i) % tableSize;
            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = elem;
                break;
            }
            i++;
        }

    }

    for (int i = 0; i < tableSize; ++i) {
        cout << hashTable[i];
        if (i != tableSize - 1) {
            cout << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }
    int tableSize;
    cin >> tableSize;

    quadraticProbing(elements, tableSize);
    return 0;
}
