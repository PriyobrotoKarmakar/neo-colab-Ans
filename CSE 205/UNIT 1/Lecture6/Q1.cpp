// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>ans;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        string S;
        cin>>S;
        ans.push_back(S);
    }
    sort(ans.begin(),ans.end());
    for(int  i=0;i<num;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}