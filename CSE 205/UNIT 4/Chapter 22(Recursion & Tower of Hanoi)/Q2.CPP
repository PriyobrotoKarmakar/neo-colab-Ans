#include<iostream>
using namespace std;

int solve(int n, char from, char to, char aux) {
    if(n == 0) return 0;
    if(n == 1) {
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        return 1;
    }
    
    int step = solve(n - 1, from, aux, to);
    step++;
    
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    
    step += solve(n - 1, aux, to, from);
    return step;
}

int main() {
    int n;
    cin >> n;
    int step = solve(n, 'A', 'C', 'B');
    cout << "Total number of times the disk is moved: " << step;
    return 0;
}
