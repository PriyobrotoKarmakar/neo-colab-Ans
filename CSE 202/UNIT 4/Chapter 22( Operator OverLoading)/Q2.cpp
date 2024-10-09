#include<bits/stdc++.h>
using namespace std;

class Time{
    public:
    int HH, MM;
    Time(int hh, int mm){
        HH = hh;
        MM = mm;
    }
};

ostream& operator<<(ostream& Cout, Time& T){
    Cout << T.HH << ":";
    Cout << setw(2) << setfill('0') << T.MM;
    return Cout;
}

void operator--(Time& T){
    if (T.HH == 0 && T.MM == 0){
        cout << "Cannot decrement further. Time is already at ";
        cout << "00:00";
        cout << "." << endl;
    }
    else if (T.MM == 0){
        T.MM = 59;
        T.HH--;
    }
    else{
        T.MM--;
    }
}

int main(){
    int hh, mm;
    cin >> hh >> mm;
    Time T(hh, mm);
    cout << "Time before decrement: ";
    cout << T <<endl;
    --T;
    cout << "\nTime after decrement: ";
    cout << T;
    return 0;
}
