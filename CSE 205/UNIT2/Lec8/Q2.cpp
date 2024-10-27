// You are using GCC
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    char data;
    Node* next;
    Node(char data){
        this->data  = data;
        this->next = NULL;
    }
};
void insertAtTail(Node* &head,Node* &tail,char val){
    Node* newNode= new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
int getlength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtPos(Node* &head,Node* &tail,int pos,char val){
    Node* newNode = new Node(val);
    int len = getlength(head);
    if(len==0){
        insertAtTail(head,tail,val);
    }
    else if(pos==1){
        newNode->next = head;
        head = newNode;
    }
    else if(pos==len+1){
        insertAtTail(head,tail,val);
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        
        while(--pos){
            prev = curr;
            curr= curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}
void printing(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    int size;
    cin>>size;
    Node* head = NULL;
    Node* tail = NULL;
    while(size--){
        char val;
        cin>>val;
        insertAtTail(head,tail,val);
    }
    cout<<"Current Linked List: ";
    printing(head);
    char val;
    int pos;
    cin>>val;
    cin>>pos;
    insertAtPos(head,tail,pos,val);
    cout<<"Updated Linked List: ";
    printing(head);
    return 0;
}