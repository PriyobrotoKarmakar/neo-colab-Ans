#include <iostream>
using namespace std;
#define MAX_VERTICES 100

// You are using GCC
#include<bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 100
unordered_map<int,vector<int>>graph;
void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    //Type your code
    graph[v].push_back(w);
}
void solve(vector<bool>&visit,int v,int V){
    visit[v] = true;
    cout<<v<<" ";
    for(auto ele : graph[v]){
        if(!visit[ele]){
            visit[ele] = true;
            solve(visit,ele,V);
        }
    }
}
void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int start) {
    //Type your code
    vector<bool> visit(V,false);

            solve(visit,start,V);
  
    
}
int main() {
    int V, E;
    cin >> V;
    cin >> E;

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        addEdge(adj, v, w);
    }

    int startVertex;
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, visited, V, startVertex);

    return 0;
}