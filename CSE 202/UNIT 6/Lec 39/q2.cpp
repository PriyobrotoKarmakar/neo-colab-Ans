#include <iostream>
#include <string>
using namespace std;

// Template function for concatenating integers
template <typename T>
T concat(T a, T b) {
    return a + b;
}

// Overloaded function for concatenating strings without a delimiter
string concat(string a, string b) {
    return a + b;
}

// Overloaded function for concatenating strings with a delimiter
string concat(string a, string b, const string& delimiter) {
    return a + delimiter + b;
}

int main() {
    int arr1[3], arr2[3];
    string str1, str2, delimiter;

    // Input for the arrays
    for (int i = 0; i < 3; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> arr2[i];
    }

    // Concatenate and print the arrays
    cout << "Concatenated array: ";
    for (int i = 0; i < 3; i++) {
        cout << concat(arr1[i], arr2[i]) << " ";
    }
    cout << endl;

    // Input for the strings and delimiter
    cin >> str1 >> str2 >> delimiter;

    // Concatenate and print the strings
    cout << "Concatenated string: " << concat(str1, str2, delimiter) << endl;

    return 0;
}
