#include <stdio.h>

#define MAXN 100
#define INF 10000000

int dis[MAXN][MAXN];  // Distance matrix
int Next[MAXN][MAXN]; // Path reconstruction matrix

// Initialize distance and next matrices
void initialise(int V, int graph[MAXN][MAXN]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j) {
                Next[i][j] = j;  
            } else {
                Next[i][j] = -1; 
            }
        }
    }
}

// Floyd-Warshall algorithm to compute shortest paths
void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If a shorter path is found, update the distance and the next vertex
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];  // Update path reconstruction
                }
            }
        }
    }
}

// Print the path from source to destination
void printPath(int path[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" -> ");
        }
        printf("%d", path[i]);
    }
    printf("\n");
}

int main() {
    int V;
    scanf("%d", &V);

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;  // No edge between i and j
            }
        }
    }

    initialise(V, graph);  // Initialize the distance and next matrices
    floydWarshall(V);  // Compute shortest paths

    int u, v;
    scanf("%d %d", &u, &v);

    int path[MAXN];
    int index = 0;
    path[index++] = u;

    // Reconstruct the path from u to v
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    // Print the shortest path
    printf("Shortest path from %d to %d: ", path[0], path[index - 1]);
    printPath(path, index);

    return 0;
}
