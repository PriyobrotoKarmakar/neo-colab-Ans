// You are us
#include <iostream>
using namespace std;

// Abstract base class
class Account {
public:
    virtual void deposit(int amount) = 0;      
    virtual void withdraw(int amount) = 0;    
    virtual void displayBalance() = 0;         
    virtual ~Account() {}                      
};


class SavingsAccount : public Account {
private:
    int balance; 

public:
    
    SavingsAccount() : balance(0) {}

   
    void deposit(int amount) override {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }

    
    void withdraw(int amount) override {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        }
    }

    
    void displayBalance() override {
        cout << "Savings Account Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount account; 
    int operation, amount;

    
    while (true) {
        cin >> operation; 
        if (operation == 1) {
            cin >> amount; 
            account.deposit(amount);
        } else if (operation == 2) {
            cin >> amount; 
            account.withdraw(amount);
        } else if (operation == 3) {
            account.displayBalance(); 
        } else if (operation == 0) {
            cout << "Exiting" << endl; 
            break;
        } else {
            cout << "Invalid operation" << endl; 
        }
    }

    return 0;
}
