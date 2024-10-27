// You are using GCC
#include<iostream>
using namespace std;
void printing(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            printf("Plant species %d is present in the collection",target);
            return;
            
        }
    }
    printf("Plant species %d is not present in the collection",target);
    
}
int main(){
    int size;
    cin>>size;
    int arr[20];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    printing(arr,size,target);
    return 0;
}