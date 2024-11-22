// You are using GCC
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>

using namespace std;

const int MAX_CAPACITY = 30;

class DuplicateIDException : public runtime_error {
public:
    DuplicateIDException() : runtime_error("Exception caught. Error: Student ID already exists.") {}
};

class FullDatabaseException : public runtime_error {
public:
    FullDatabaseException() : runtime_error("Exception caught. Error: Student database is full.") {}
};

int main() {
    int n;
    cin >> n;

    set<int> studentIDs;
    n = n>30 ? 31 : n;
    for (int i = 0; i < n; i++) {
        int studentID;
        string studentName;
        
        cin >> studentID >> studentName;
        
        try {
            if (studentIDs.size() >= MAX_CAPACITY) {
                throw FullDatabaseException();
            }
            if (studentIDs.find(studentID) != studentIDs.end()) {
                throw DuplicateIDException();
            }
            
            studentIDs.insert(studentID);
            cout << "Student with ID " << studentID << " added to the database." << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
