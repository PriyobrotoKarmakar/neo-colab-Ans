// You are using GCC
#include <iostream>
using namespace std;

#define MAX_SIZE 100

void traverseInventory(int arr[], int size) {
    //Type your code here
    cout<<"Inventory List: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertItem(int arr[], int &size, int item) {
    //Type your code here
    cout<<"Inserting Item: "<<item<<endl;
    arr[size] = item;
    size++;
    traverseInventory(arr,size);
    
}
void removeCurr(int arr[],int &size,int pos){
    for(int i=pos;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    
}
void removeItem(int arr[], int &size, int item) {
    cout<<"Removing Item: "<<item<<endl;
    //Type your code here
    int pos;
    for(int i=0;i<size;i++){
        if(arr[i]==item){
            pos = i;
            break;
        }
    }
    removeCurr(arr,size,pos);
    // size--;
    traverseInventory(arr,size);
}

int main() {
    int inventory[MAX_SIZE];
    int size, n, m;
    int newItems[MAX_SIZE];
    int deleteItems[MAX_SIZE];

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> inventory[i];
    }

    traverseInventory(inventory, size);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> newItems[i];
    }
    for (int i = 0; i < n; i++) {
        insertItem(inventory, size, newItems[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> deleteItems[i];
    }
    for (int i = 0; i < m; i++) {
        removeItem(inventory, size, deleteItems[i]);
    }

    return 0;
}