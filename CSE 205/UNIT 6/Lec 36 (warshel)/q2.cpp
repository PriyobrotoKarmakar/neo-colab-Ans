#include <iostream>
using namespace std;

#define MAX_NODES 100


bool hasChainOfConnections(int n, int connections[MAX_NODES][MAX_NODES], int source, int target) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (connections[i][j] == 0 && connections[i][k] && connections[k][j]) {
                    connections[i][j] = 1;
                }
            }
        }t
    }
    return connections[source][target] == 1;
}


int main() {
    int n; // Number of nodes
    cin >> n;

    int connections[MAX_NODES][MAX_NODES] = {0};

    // Taking input for direct connections
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> connections[i][j];
        }
    }

    int source, target;
    cin >> source >> target;

    if (hasChainOfConnections(n, connections, source, target)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}