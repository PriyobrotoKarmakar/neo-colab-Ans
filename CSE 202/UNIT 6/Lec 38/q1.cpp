// You are using GCC
#include <iostream>
#include <stdexcept>

using namespace std;

void categorizeSentiment(int num) {
    try {
        if (num > 0) {
            throw 1;
        } else if (num < 0) {
            throw -1;
        } else {
            throw 0;
        }
    } catch (int sentiment) {
        if (sentiment == 1) {
            cout << "You Entered Positive number" << endl;
        } else if (sentiment == -1) {
            cout << "You Entered Negative number" << endl;
        } else {
            cout << "You Entered Zero" << endl;
        }
    }
}

int main() {
    int num;
    cin >> num;
    
    categorizeSentiment(num);

    return 0;
}
