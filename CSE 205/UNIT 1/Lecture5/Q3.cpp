#include<iostream>
using namespace std;
int find(int arr[],int size,int target){
    int start = 0;
    int end = size-1;
    int ans=0;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(target>arr[mid]){
            start =mid+1;
            ans = start;
        }
        else{
            end = mid-1;
            
        }
    }
    return ans;
}
int main(){
    int size;
    cin>>size;
    int arr[120];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<find(arr,size,target);
    
    return 0;
}