#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> st;
    int tc;
    cin >> tc;
    cin.ignore();
    
    while (tc--) {
        int id;
        string name;
        cin >> id;
        cin.ignore();
        getline(cin, name);
        st[id] = name;
    }
    
    int id;
    cin >> id;
    if (st.find(id) != st.end()) {
        cout << "Student name: " << st[id] << endl;
    } else {
        cout << "Student name: Student not found" << endl;
    }
    
    return 0;
}
