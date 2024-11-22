#include <iostream>
using namespace std;

template <typename T1, typename T2>
class PairBase {
protected:
    T1 first;
    T2 second;

public:
    PairBase(T1 f, T2 s) : first(f), second(s) {}

    void swap() {
        T1 temp = first;
        first = second;
        second = temp;
    }

    void display() const {
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
    }
};

template <typename T1, typename T2>
class PairDerived : public PairBase<T1, T2> {
public:
    PairDerived(T1 f, T2 s) : PairBase<T1, T2>(f, s) {}
};

int main() {
    float a;
    double b;

    cin >> a;
    cin >> b;

    PairDerived<float, double> p(a, b);

    cout << "Values before swap: " << endl;
    p.display();

    p.swap();

    cout << "Values after swap: " << endl;
    p.display();

    return 0;
}
