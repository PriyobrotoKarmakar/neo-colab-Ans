#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void floydWarshall(int **graph, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != 999 && graph[k][j] != 999) {
                    if(graph[i][k]+graph[k][j]<graph[i][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                    }
                }
            }
        }
    }
}

int main(void) {
    int n, i, j;
    cin >> n;
    int **graph = (int **)malloc((long unsigned)n * sizeof(int *));
    for (i = 0; i < n; i++) {
        graph[i] = (int *)malloc((long unsigned)n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    floydWarshall(graph, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
