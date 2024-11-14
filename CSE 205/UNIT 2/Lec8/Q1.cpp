// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        next = NULL;
    }
};
void inserting(Node* &head,Node* &tail,int val){
    
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}
void printing(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int size;
    cin>>size;
    Node* head = NULL;
    Node* tail = NULL;
    while(size--){
        int temp;
        cin>>temp;
        inserting(head,tail,temp);
    }
    cout<<"Created Linked list: ";
    printing(head);
    int temp;
    cin>>temp;
    inserting(head,tail,temp);
    cout<<"Final List: ";
    printing(head);
    
    
    return 0;
}