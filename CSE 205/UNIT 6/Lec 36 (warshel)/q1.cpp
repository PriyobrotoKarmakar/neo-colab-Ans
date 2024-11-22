#include<bits/stdc++.h>
using namespace std;
bool isCycle(unordered_map<int,list<int>>&adj,vector<bool>&visited,int u,vector<bool>&dfsVisited){
    visited[u] = true;
    dfsVisited[u] = true;
    for(auto &ele : adj[u]){
        if(!visited[ele] && isCycle(adj,visited,ele,dfsVisited))return true;
        if(dfsVisited[ele])return true;
    }
    dfsVisited[u] = false;
    return false;
}
bool solve(unordered_map<int,list<int>>&adj,int n){
    vector<bool>visited(n,false);
    vector<bool>dfsVisited(n,false);
    for(int i = 0;i<n;i++){
        if(!visited[i] && isCycle(adj,visited,i,dfsVisited)){
            return true;
        }
    }
    return false;
}
int main(){
    unordered_map<int,list<int>>adj;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int v,u;
        cin>>v>>u;
        adj[v].push_back(u);
    }
    
    if(solve(adj,n))cout<<"No";
    else cout<<"Yes";
    return 0;
}