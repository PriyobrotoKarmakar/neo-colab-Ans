#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> convert(const vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    map<int, int> valueToIndex;
    for (int i = 0; i < sortedArr.size(); i++) {
        if (valueToIndex.find(sortedArr[i]) == valueToIndex.end()) {
            valueToIndex[sortedArr[i]] = i;
        }
    }

    vector<int> reducedForm;
    for (int num : arr) {
        reducedForm.push_back(valueToIndex[num]);
    }
    
    return reducedForm;
}

void printArr(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Input Array: ";
    printArr(arr);

    vector<int> reducedArr = convert(arr);
    cout << "Converted Array: ";
    printArr(reducedArr);

    return 0;
}
