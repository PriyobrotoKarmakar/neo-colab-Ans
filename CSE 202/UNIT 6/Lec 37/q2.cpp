// You are using GCC
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        string mobileNumber;
        cin >> mobileNumber;


        for (char ch : mobileNumber) {
            if (!isdigit(ch)) {
                throw invalid_argument("Invalid input");
                return 0;
            }
        }

        cout << mobileNumber << endl;
        if (mobileNumber.length() != 10) {
            throw length_error("The mobile number should have 10 digits");
        }

        cout << "The entered mobile number is valid" << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    } catch (const length_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}
