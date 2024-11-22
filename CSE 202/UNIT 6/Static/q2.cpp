#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T calculateTotalRevenue(const vector<T>& bookings) {
    T totalRevenue = 0;
    for (T amount : bookings) {
        totalRevenue += amount;
    }
    return totalRevenue;
}

int main() {
    int n;
    cin >> n;
    
    vector<double> bookings(n);
    for (int i = 0; i < n; ++i) {
        cin >> bookings[i];
    }
    
    double totalRevenue = calculateTotalRevenue(bookings);
    cout << totalRevenue << endl;
    
    return 0;
}
    