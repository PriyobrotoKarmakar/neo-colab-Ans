#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<sstream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
TreeNode* createTree(vector<int>&arr,int index){
    //base case
    if(index>=arr.size())return NULL;
    //N: create node from curr element
    int currEle = arr[index];
    TreeNode* root = new TreeNode(currEle);

    //L: index = index*2+1
    root->left = createTree(arr,(index*2)+1);
    //R: index = index*2+2
    root->right = createTree(arr,(index*2)+2);

    return root;

}
void LevelOrderPrinting(TreeNode* root){
    if(root==NULL)return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            q.pop();
        }
        cout<<endl;
    }
}
int main(){
    TreeNode* root = NULL;
    vector<int> levelOrder{1,2,3,4,5,6,7,8,9};
    int index = 0;
    root = createTree(levelOrder,index);
    LevelOrderPrinting(root);
    return 0;
}