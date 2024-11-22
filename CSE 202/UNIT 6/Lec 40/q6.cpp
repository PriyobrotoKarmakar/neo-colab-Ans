#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int pos;
    cin >> pos;

    try {
        if (pos >= 0 && pos < n) {
            cout << numbers[pos] << endl;
        } else {
            throw out_of_range("Exception occurred!\n Not possible to fetch index " + to_string(pos));
        }
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}
