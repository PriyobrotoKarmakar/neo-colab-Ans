// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>ans;
    int size1;
    cin>>size1;
    int arr[100];
    for(int i=0;i<size1;i++){
        cin>>arr[i];
    }
    
    
    int size2;
    cin>>size2;
    int brr[100];
    for(int i=0;i<size2;i++){
        cin>>brr[i];
    }
    
    int m=0,n=0;
    while(m<size1 and n<size2){
        if(arr[m]>brr[n]){
            ans.push_back(brr[n++]);
        }
        else{
            ans.push_back(arr[m++]);
        }
    }
    
    while(m<size1){
        ans.push_back(arr[m++]);
    }
    
    
    while(n<size2){
        ans.push_back(brr[n++]);
    }
    for(auto ch:ans){
        cout<<ch<<" ";
    }
    return 0;
}