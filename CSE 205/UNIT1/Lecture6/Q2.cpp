// You are using GCC
#include<bits/stdc++.h>
using namespace std;
// int findMin(int arr[],int size,int check){
//     int mini = INT_MAX;
//     int ans;
//     for(int i=check+1;i<size;i++){
//         if(mini>arr[i]){
//             mini = arr[i];
//             ans = i;
//         }
//     }
//     return ans;
// }
void printing(int arr[],int size,int count){
    cout<<"Height order of students after iteration "<<count<<": ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Student's height order before sorting: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int count = 1;
    for(int i=0;i<size-1;i++){
        int minIndex = i;
        bool check = false;
        for(int j=i+1;j<size;j++){
            if(arr[minIndex]>arr[j]){
                check = true;
                minIndex = j;
            }
        }
        
        swap(arr[i],arr[minIndex]);
        printing(arr,size,count++);
            
        
    }
    cout<<"After final comparison of all students, the height order becomes: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}