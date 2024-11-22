#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <typename T>
class BankAccount {
public:
    BankAccount(const string& accountNumber, const string& accountHolder, T balance)
        : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

    void deposit(T amount) {
        balance += amount;
        cout << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(T amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void displayDetails() const {
        cout << accountNumber << " " << accountHolder << " " << fixed << setprecision(2) << balance << endl;
    }

protected:
    string accountNumber;
    string accountHolder;
    T balance;
};

template <typename T>
class SavingsAccount : public BankAccount<T> {
public:
    SavingsAccount(const string& accountNumber, const string& accountHolder, T balance, double interestRate)
        : BankAccount<T>(accountNumber, accountHolder, balance), interestRate(interestRate) {}

    void displayDetails() const {
        cout << "Savings Account Details: " << endl;
        BankAccount<T>::displayDetails();
        cout << fixed << setprecision(2) << interestRate << "%" << endl;
    }

private:
    double interestRate;
};

int main() {
    string accountNumber, accountHolder;
    double balance, interestRate;
    double depositAmount, withdrawAmount;

    cin >> accountNumber;
    cin.ignore();
    getline(cin, accountHolder);

    cin >> balance;
    cin >> interestRate;

    SavingsAccount<double> savingsAccount(accountNumber, accountHolder, balance, interestRate);

    savingsAccount.displayDetails();

    cin >> depositAmount;
    savingsAccount.deposit(depositAmount);

    cin >> withdrawAmount;
    savingsAccount.withdraw(withdrawAmount);

    return 0;
}
