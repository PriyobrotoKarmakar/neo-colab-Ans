#include <bits/stdc++.h>

using namespace std;

int calHash(int key, int size) {
    return key % size;
}

int main() {
    int size, n;
    cin >> size >> n;

    vector<int> hashTable(size, -1);
    vector<pair<int, int>> result;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int index = calHash(key, size);
        int ogindex = index;
        while (hashTable[index] != -1) {
            index = (index + 1) % size;
            if(index==ogindex)break;
        }
        if(hashTable[index]==-1){
            hashTable[index] = key;
            result.push_back({index, key});
        }
    }

    sort(result.begin(), result.end());

    for (auto& entry : result) {
        cout << "index: " << entry.first << ", value: " << entry.second << endl;
    }
      return 0;
}
