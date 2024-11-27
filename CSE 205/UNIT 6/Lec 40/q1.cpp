#include <iostream>
using namespace std;

void readKeys(int keys[], int numKeys) {
    for (int i = 0; i < numKeys; i++) {
        cin >> keys[i];
    }
}
void initializeHashTable(int hashTable[], int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
}

void insertKeys(int hashTable[], int tableSize, int keys[], int numKeys) {
    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int index = key % tableSize; 
        while (hashTable[index] != -1) { 
            index = (index + 1) % tableSize; 
        }
        hashTable[index] = key;
    }
}

void findFirstAndLast(int hashTable[], int tableSize, int& first, int& last, int& firstIndex, int& lastIndex) {
    first = -1;
    last = -1;
    firstIndex = -1;
    lastIndex = -1;

    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            if (first == -1) {
                first = hashTable[i];
                firstIndex = i;
            }
            last = hashTable[i];
            lastIndex = i;
        }
    }
}



int main() {
    const int tableSize = 10;
    int numKeys;
    cin >> numKeys;

    int keys[numKeys];
    readKeys(keys, numKeys);

    int hashTable[tableSize];
    initializeHashTable(hashTable, tableSize);

    insertKeys(hashTable, tableSize, keys, numKeys);

    int first, last, firstIndex, lastIndex;
    findFirstAndLast(hashTable, tableSize, first, last, firstIndex, lastIndex);

    if (first != -1 && last != -1) {
        cout << "First index: " << firstIndex << ", Value: " << first << endl;
        cout << "Last index: " << lastIndex << ", Value: " << last << endl;
    }

    return 0;
}

