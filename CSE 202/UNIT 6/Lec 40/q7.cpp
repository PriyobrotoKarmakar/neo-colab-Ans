#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void removeElement(vector<int>& petDataList, int target) {
    petDataList.erase(remove(petDataList.begin(), petDataList.end(), target), petDataList.end());
}

int main() {
    int N;
    cin >> N;
    
    vector<int> petDataList(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> petDataList[i];
    }
    
    int M;
    cin >> M;
    
    removeElement(petDataList, M);
    
    if (petDataList.empty()) {
        cout << M << endl;
    } else {
        for (int i = 0; i < petDataList.size(); ++i) {
            if (i != 0) cout << " ";
            cout << petDataList[i];
        }
        cout << endl;
    }
    
    return 0;
}
