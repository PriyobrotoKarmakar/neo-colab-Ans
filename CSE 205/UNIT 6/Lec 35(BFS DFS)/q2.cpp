// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class graph{
  public:
    unordered_map<int,list<int>>adj;
    void insert(int u,int v){
        adj[u].push_back(v);
    }
    bool validPath(int s,int d,vector<bool>&visited,vector<int>&path){
        visited[s] = true;
        path.push_back(s);
        if(s==d)return true;
        for(auto ele:adj[s]){
            if(!visited[ele]){
                visited[ele] = true;
                if(validPath(ele,d,visited,path)){
                    return true;
                }
            }
        }
        
        path.pop_back();
        return false;
    }
};
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    graph G;
    vector<bool>visited(nodes,false);
    while(edges--){
        int u,v;
        cin>>u>>v;
        G.insert(u,v);
    }
    int s,d;
    cin>>s>>d;
    vector<int>path;
    int ans = G.validPath(s,d,visited,path);
    if(ans){
        cout<<"There is a path from "<<s<<" to "<<d<<endl;
    }else{
        cout<<"There is no path from "<<s<<" to "<<d<<endl;
        
    }
    return 0;
}