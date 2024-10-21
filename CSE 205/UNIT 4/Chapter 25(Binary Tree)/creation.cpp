#include<iostream>
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
TreeNode* createTree(int val){
    if(val==-1){
        return NULL;
    }
    TreeNode* root  = new TreeNode(val);

    cout<<"value for left child of" <<val<<": "<<endl;
    int lc ;
    cin>>lc;
    root->left = createTree(lc);
    cout<<"value for right child"<<val<<": "<<endl;
    int rc ;
    cin>>rc;
    root->right = createTree(rc);

    return root;
}
void printing(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printing(root->left);
    printing(root->right);
}
int main(){
    // TreeNode root(5);
    TreeNode* root = NULL;
    cout<<"please enter the value for root node: ";
    int val;
    cin>>val;
    root = createTree(val);
    cout<<"printing"<<endl;
    printing(root);
    return 0;
}