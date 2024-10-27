// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    vector<int> ans;
    while(size--){
        int temp;
        cin>>temp;
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    for(auto ch: ans){
        cout<<ch<<" ";
    }
    return 0;
}