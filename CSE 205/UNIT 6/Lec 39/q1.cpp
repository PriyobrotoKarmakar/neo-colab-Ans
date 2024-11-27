#include <iostream>
using namespace std;
int SIZE = 100;


int calHash(int key, int size)
{
    return key % size;
}

int main() {
    int N, K;
    cin >> N >> K;
    int slots[K];
    for (int i = 0; i < K; i++) {
        cin >> slots[i];
    }
    
    int hashTable[N];
    for (int i = 0; i < N; i++) {
        hashTable[i] = -1;
    }
    
    for (int i = 0; i < K; i++) {
        int key = slots[i];
        int index = calHash(key, N);
        int originalIndex = index;
        
        while (hashTable[index] != -1) {
            index = (index + 1) % N;
            if (index == originalIndex) break;  
        }
        
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            cout << index << " ";
        } else {
            cout << "-1 ";  
        }
    }
    

return 0;
}