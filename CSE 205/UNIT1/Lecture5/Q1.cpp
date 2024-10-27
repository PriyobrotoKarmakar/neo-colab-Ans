// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int arr[20];
    int target;
    int size;
    int count =0;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cin>>target;
    for(int i=0;i<size;i++){
        if(arr[i]<=target){
            count++;
        }
    }
    cout<<count;
    return 0;
}