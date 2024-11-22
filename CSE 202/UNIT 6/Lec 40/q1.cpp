#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
    virtual void displayDetails() = 0;
};

class Circle : public Shape {
private:
    double radius, area;
public:
    Circle(double r) : radius(r) { calculateArea(); }
    void calculateArea() override { area = M_PI * radius * radius; }
    void displayDetails() override {
        cout << "Circle Details:" << endl;
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << fixed << setprecision(4) << area << endl;
    }
};

class Cube : public Shape {
private:
    double side, surfaceArea;
public:
    Cube(double s) : side(s) { calculateArea(); }
    void calculateArea() override { surfaceArea = 6 * side * side; }
    void displayDetails() override {
        cout << "Cube Details:" << endl;
        cout << "Cube with side length: " << side << endl;
        cout << "Surface area: " << round(surfaceArea) << endl;
    }
};

int main() {
    int shapeType;
    cin >> shapeType;
    if (shapeType == 1) {
        double radius;
        cin >> radius;
        Circle circle(radius);
        circle.displayDetails();
    } 
    else if (shapeType == 2) {
        double side;
        cin >> side;
        Cube cube(side);
        cube.displayDetails();
    } 
    else {
        cout << "Invalid shape type selected." << endl;
    }
    return 0;
}
