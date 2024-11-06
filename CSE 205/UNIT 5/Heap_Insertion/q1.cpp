// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void heap(vector<int>&pq,int val){
    pq.push_back(val);
    int index = pq.size()-1;
    while(index>1){
        int child = index;
        int parent = child/2;
        if(pq[child]>pq[parent]){
            swap(pq[child],pq[parent]);
        }else{
            break;
        }
        index = parent;
    }
}
void printing(vector<int>pq){
    for(int i=1;i<pq.size();i++){
        int ele = pq[i];
        cout<<ele<<" ";
    }
    cout<<endl;
}
void printingSq(vector<int>pq){
    for(int i=1;i<pq.size();i++){
        int ele = pq[i];
        cout<<ele*ele<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>pq;
    pq.push_back(0);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        heap(pq,val);
    }
    printing(pq);
    printingSq(pq);
    return 0;
}