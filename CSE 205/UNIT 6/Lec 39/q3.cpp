#include <iostream>
#include <string>
using namespace std;

#define HASH_TABLE_SIZE 1000

unsigned int customHash(string key) {
    unsigned int hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 37) + ch;
    }
    return hashValue % HASH_TABLE_SIZE;
}

int main() {
    string subject;
    while (true) {
        getline(cin, subject);
        if (subject == "exit") {
            break;
        }
        cout << customHash(subject) << endl;
    }
    return 0;
}
