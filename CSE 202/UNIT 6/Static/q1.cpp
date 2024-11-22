// You are 
#include <iostream>
#include <string>
using namespace std;

bool isValidEmail(string email) {
    if (email.empty()) return false;
    
    if (!isalpha(email[0])) return false;
    
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);
    
    if (atPos == string::npos || dotPos == string::npos || atPos > dotPos || dotPos == email.length() - 1) {
        return false;
    }
    
    return true;
}

int main() {
    string email;
    cin >> email;
    
    try {
        if (isValidEmail(email)) {
            cout << "Email Id is Valid." << endl;
        } else {
            throw "Invalid Email Id!!!";
        }
    } catch (const char* e) {
        cout << "Exception Caught..." << endl;
        cout << e << endl;
    }
    
    return 0;
}
