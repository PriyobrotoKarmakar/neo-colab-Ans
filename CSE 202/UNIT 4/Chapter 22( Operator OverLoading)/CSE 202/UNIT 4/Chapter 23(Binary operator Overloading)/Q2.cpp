#include<bits/stdc++.h>
using namespace std;

class com{
    public:
    float real;
    float img;
    
    com(float r, float i) {
        real = r;
        img = i;
    }
};

com operator+(com& c1, com& c2) {
    com temp(0, 0);
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}

com operator-(com& c1, com& c2) {
    com temp(0, 0);
    temp.real = c1.real - c2.real;
    temp.img = c1.img - c2.img;
    return temp;
}

ostream& operator<<(ostream& Cout, com& C) {
    if (C.img >= 0) {
        printf("%.2f + ", C.real);
        printf("%.2fi\n", C.img);
    } else {
        printf("%.2f - ", C.real);
        printf("%.2fi\n", (-1)*C.img);
    }
    return Cout;
}

int main() {
    float r1, r2, i1, i2;
    cin >> r1 >> i1;
    cin >> r2 >> i2;
    
    com C1(r1, i1);
    com C2(r2, i2);
    
    com add = C1 + C2;
    com sub = C1 - C2;
    
    cout << add << sub;
    
    return 0;
}
