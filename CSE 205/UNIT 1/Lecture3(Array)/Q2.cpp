// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    size--;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}