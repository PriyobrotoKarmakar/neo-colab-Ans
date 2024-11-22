// You are using GCC
#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

class ShoppingCart {
private:
    unordered_map<string, pair<int, double>> cart;  // Stores item name, quantity, and price

public:
    void addItem(const string& name, int quantity, double price) {
        cart[name] = make_pair(quantity, price);
}

    void updateQuantity(const string& name, int quantity) {
        if (cart.find(name) != cart.end()) {
            cart[name].first = quantity;
        } else {
            cout << "Item not found in the cart.\n";
        }
    }

    void viewTotalBill() {
        double total = 0.0;
        for (const auto& item : cart) {
            total += item.second.first * item.second.second;  // quantity * price
        }
        // cout << fixed << setprecision(2);
        cout << "Total Bill: " << total << endl;
    }

    void exitProgram() {
        cout << "Exiting the program.\n";
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string itemName;
    int quantity;
    double price;

    while (true) {
        cin >> choice;
        cin.ignore();  // to ignore the newline character after reading choice

        switch (choice) {
            case 1:  // Ad
                getline(cin, itemName);
                cin >> quantity;
                cin >> price;
                cart.addItem(itemName, quantity, price);
                break;

            case 2:  // Update Quantity
                    getline(cin, itemName);
                
                cin >> quantity;
                cart.updateQuantity(itemName, quantity);
                break;

            case 3:  // View Total Bill
                cart.viewTotalBill();
                break;

            case 4:  // Exit
                cart.exitProgram();
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
