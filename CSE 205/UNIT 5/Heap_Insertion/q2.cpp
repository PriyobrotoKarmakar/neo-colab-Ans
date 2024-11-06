// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int size,int i ){
    int smallest = i;
    int left = (i*2) + 1;
    int right = (i*2) + 2;
    if(left<size && arr[left]<arr[smallest]){
        smallest = left;
    }
    if(right<size && arr[right]<arr[smallest]){
        smallest = right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(arr,size,smallest);
    }
}
void heap(vector<int>&arr){
    for(int i=(arr.size()/2)-1;i>=0;i--)
        heapify(arr,arr.size(),i);   
}
void printing(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void solve(vector<int>arr,int t){
    int count = 0;
    // sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i]<t){
            count++;
        }
    }
    cout<<count;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    // arr.push_back(INT_MIN);
    while(n--){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    heap(arr);
    int threshold;
    cin>>threshold;
    printing(arr);
    solve(arr,threshold);
 return 0;   
}