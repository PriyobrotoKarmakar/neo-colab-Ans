// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void heapifyDOWN(vector<int>&arr,int size,int index){
    int small = index;
    int left = (small*2)+1;
    int right = (small*2)+2;
    if(left<size && arr[left]<arr[small])
        small = left;
    
    if(right<size && arr[right]<arr[small])
        small = right;
        
    if(small!=index){
        swap(arr[index],arr[small]);
        heapifyDOWN(arr,size,small);
    }
    
}
void heap(vector<int>&arr,int size){
    for(int i=(size/2)-1;i>=0;i--)
        heapifyDOWN(arr,size,i);
}
void insert(vector<int>&arr2,int val){
    arr2.push_back(val);
    int i = arr2.size()-1;
    while(i>0){
        int child = i;
        int parent = (child-1)/2;
        if(arr2[parent]>arr2[child]){
            swap(arr2[parent],arr2[child]);
            i = parent;
        }else{
            break;
        }
    }
}
void printing(vector<int>&arr,int target){
    bool check = false;
    for(auto ele:arr){
        cout<<ele<<" ";
        if(ele==target){
            check = true;
        }
    }
    cout<<endl;
    if(check){
        cout<<target<<" is present"<<endl;
    }else{
        cout<<target<<" is not present"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>pq;
    vector<int>arr2;
    int val;
    while(n--){
        cin>>val;
        insert(arr2,val);
        pq.push_back(val);
    }
    heap(pq,pq.size());
    int target;
    cin>>target;
    // printing(pq,target);
    printing(arr2,target);
    return 0;
}