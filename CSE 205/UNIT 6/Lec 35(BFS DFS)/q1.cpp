// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class graph{
  public:
    unordered_map<int,list<int>>adj;
    void insert(int u,int v){
        adj[u].push_back(v);
    }
    void BFS(int u,vector<bool>&visited){
        queue<int>q;
        visited[u] = true;
        q.push(u);
        while(!q.empty()){
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            for(auto& ele: adj[front]){
                if(!visited[ele]){
                    q.push(ele);
                    visited[ele] = true;
                }
            }
        }
    }
    
};
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    vector<bool>visited(nodes,false);
    graph G;
    while(edges--){
        int s,d;
        cin>>s>>d;
        G.insert(s,d);
    }
    
    G.BFS(0,visited);
    return 0;
}