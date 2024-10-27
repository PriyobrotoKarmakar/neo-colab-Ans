// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    getline(cin,S,'\n');
    // cout<<S;
    int count =1;
    for(int i=1;i<S.length()-1;i++){
        if((S[i]!=' ') && (S[i+1]==' ')){
            count++;
        }
    }
    cout<<count;
    return 0;
}