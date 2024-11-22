#include <iostream>
#include <vector>

using namespace std;

void removeElement(vector<int>& arr, int target) {
    vector<int> result;
    for (int id : arr) {
        if (id != target) {
            result.push_back(id);
        }
    }
    arr = result;
}

int main() {
    int N, M;
    cin >> N;
    
    vector<int> patientIds(N);
    for (int i = 0; i < N; i++) {
        cin >> patientIds[i];
    }
    
    cin >> M;
    
    removeElement(patientIds, M);
    
    for (int i = 0; i < patientIds.size(); i++) {
        cout << patientIds[i];
        if (i != patientIds.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
