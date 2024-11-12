#include <iostream>
#include <iomanip>
using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;

public:
    Product(string name, double price, int quantity) 
        : name(name), price(price), quantity(quantity) {}

    virtual void addToCart(int qtyToAdd) = 0;
    virtual void displayProductDetails() = 0;

    virtual ~Product() {}
};

class Electronics : public Product {
private:
    string warranty;

public:
    Electronics(string name, double price, int quantity, string warranty) 
        : Product(name, price, quantity), warranty(warranty) {}

    void addToCart(int qtyToAdd) override {
        quantity += qtyToAdd;
    }

    void displayProductDetails() override {
        cout << "Product Name: " << name << endl;
        cout << fixed << setprecision(2) << "Price per item: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Warranty Period: " << warranty << endl;
        cout << fixed << setprecision(2) << "Total Bill: " << price * quantity << endl;
    }
};

int main() {
    string name, warranty;
    double price;
    int quantity, qtyToAdd;

    getline(cin, name);
    cin >> price;
    cin >> quantity;
    cin.ignore();
    getline(cin, warranty);
    cin >> qtyToAdd;

    Electronics product(name, price, quantity, warranty);
    product.addToCart(qtyToAdd);
    product.displayProductDetails();

    return 0;
}
