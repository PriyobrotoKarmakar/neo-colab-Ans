#include <iostream>
using namespace std;

#define MAXN 100
int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

// Function to initialize the dis and Next matrices
void initialise(int V, int graph[MAXN][MAXN]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j) {
                dis[i][j] = INF;  
                Next[i][j] = -1;   
            } else {
                dis[i][j] = graph[i][j];
                if (graph[i][j] != 0) {
                    Next[i][j] = j;  // Direct edge exists, set next as destination
                }
            }
        }
    }
}

// Function to apply the Floyd-Warshall algorithm
void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];  // Update the next vertex in the path
                }
            }
        }
    }
}

// Function to print the path
void printPath(int path[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " -> ";
        cout << path[i];
    }
    cout << endl;
}

int main() {
    int V;
    cin >> V;

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int u, v;
    cin >> u;
    cin >> v;

    int path[MAXN];
    path[0] = u;
    int index = 1;
    
    // Reconstruct the path
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    cout << "Shortest path from " << path[0] << " to " << path[index - 1] << ": ";
    printPath(path, index);

    return 0;
}
