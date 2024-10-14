#include<bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>>& arr, int start, int mid, int end) {
    int l = mid - start + 1;
    int r = end - mid;

    vector<pair<int, int>> v1(l), v2(r);
    for (int i = 0; i < l; i++) {
        v1[i] = arr[start + i];
    }
    for (int i = 0; i < r; i++) {
        v2[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int index = start;

    while (i < l && j < r) {
        
        if (v1[i].second < v2[j].second || (v1[i].second == v2[j].second && v1[i].first < v2[j].first)) {
            arr[index++] = v1[i++];
        } else {
            arr[index++] = v2[j++];
        }
    }

    while (i < l) {
        arr[index++] = v1[i++];
    }

    while (j < r) {
        arr[index++] = v2[j++];
    }
}


void mergeSort(vector<pair<int, int>>& arr, int s, int e) {
    if (s >= e) return;

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main() {
    int size;
    cin >> size;

    vector<int> v(size);
    for (int& ele : v) {
        cin >> ele;
    }


    map<int, int> freq;
    for (int ele : v) {
        freq[ele]++;
    }

  
    vector<pair<int, int>> P;
    for (const auto& ele : freq) {
        P.push_back({ele.first, ele.second});
    }

    mergeSort(P, 0, P.size() - 1);

    for (auto ele : P) {
        for (int i = 0; i < ele.second; i++) {
            cout << ele.first << " ";
        }
    }

    return 0;
}
