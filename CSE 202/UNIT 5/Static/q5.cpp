// You are using GCC
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Expression {
public:
    virtual double evaluate() = 0; 
    virtual ~Expression() {}
};

class PowerAB : public Expression {
private:
    double a, b;
public:
    PowerAB(double x, double y) : a(x), b(y) {}
    double evaluate() override {
        return pow(a, b);
    }
};

class PowerBA : public Expression {
private:
    double a, b;
public:
    PowerBA(double x, double y) : a(x), b(y) {}
    double evaluate() override {
        return pow(b, a);
    }
};

int main() {
    double a, b;
    cin >> a >> b;

    Expression* expr1 = new PowerAB(a, b);
    Expression* expr2 = new PowerBA(a, b);

    cout << fixed << setprecision(2) << expr1->evaluate() << endl;
    cout << fixed << setprecision(2) << expr2->evaluate() << endl;

    delete expr1;
    delete expr2;

    return 0;
}
