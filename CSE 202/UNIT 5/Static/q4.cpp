// You are using GCC
#include<iostream>
using namespace std;

class Color {
public:
    virtual void paint() = 0; // pure virtual function
    virtual ~Color() {}
};

class RedPaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Red color." << endl;
    }
};

class BluePaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Blue color." << endl;
    }
};

int main() {
    char choice;
    cin >> choice;

    Color* color = nullptr;

    if(choice == 'R' || choice == 'r') {
        color = new RedPaint();
    } else if(choice == 'B' || choice == 'b') {
        color = new BluePaint();
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    color->paint(); // Call the appropriate paint method

    delete color; // Clean up memory
    return 0;
}
