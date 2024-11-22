// You are using GCC
#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>
#include <iomanip>

using namespace std;

class FoodOrderingSystem {
private:
    unordered_map<string, pair<int, float>> orders;

public:
    void addOrder(const string& name, int quantity, float price) {
        orders[name] = {quantity, price};
    }

    void updateQuantity(const string& name, int quantity) {
        if (orders.find(name) != orders.end()) {
            orders[name].first = quantity;
        } else {
            cout << "Item not found in the order." << endl;
        }
    }

    void calculateTotalBill() {
        float totalBill = 0.0;
        for (const auto& order : orders) {
            totalBill += order.second.first * order.second.second;
        }
        
        cout << "Total Bill: $" << totalBill << endl;
    }
};

int main() {
    FoodOrderingSystem system;
    int choice;
    
    while (true) {
        cin >> choice;

        if (choice == 1) {
            string name;
            int quantity;
            float price;
            cin >> name >> quantity >> price;
            system.addOrder(name, quantity, price);
        }
        else if (choice == 2) {
            string name;
            int quantity;
            cin >> name >> quantity;
            system.updateQuantity(name, quantity);
        }
        else if (choice == 3) {
            system.calculateTotalBill();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
