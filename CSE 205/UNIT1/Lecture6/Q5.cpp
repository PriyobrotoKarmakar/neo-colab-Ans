// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    int arr[size];
    int count = 0;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j= i-1;
        while(j>=0 and arr[j]>key){
            arr[j+1] = arr[j];
            j--;
            count++;
        }
        arr[j+1]=key;
    }
    cout<<count;
    return 0;
}