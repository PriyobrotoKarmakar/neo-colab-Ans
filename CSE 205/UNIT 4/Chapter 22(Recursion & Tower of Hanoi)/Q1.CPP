#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int index, int prev, int &check) {
    if(index == v.size()) return;

    if(prev == v[index]) {
        cout << v[index] << " ";
        check++;
    } else {
        prev = v[index];
    }

    solve(v, index + 1, prev, check);
}

int main() {
    int size;
    cin >> size;
    vector<int> v(size);
    for(int& ele : v) {
        cin >> ele;
    }

    int check = 0;
    solve(v, 1, v[0], check);

    if(check == 0) {
        cout << -1;
    }

    return 0;
}
