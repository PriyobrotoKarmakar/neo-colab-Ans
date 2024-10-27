// You are using GCC
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> store;
    int size1,size2;
    cin>>size1;
    for(int i=0;i<size1;i++){
        int temp;
        cin>>temp;
        store.push_back(temp);
    }
    cin>>size2;
    for(int i=0;i<size2;i++){
        int temp;
        cin>>temp;
        store.push_back(temp);
    }
    sort(store.begin(),store.end());
    for(int i=0;i<size1;i++){
        cout<<store[i]<<" ";
    }
    cout<<endl;
    for(int i=size1;i<store.size();i++){
        cout<<store[i]<<" ";
    }
    
    return 0;
}