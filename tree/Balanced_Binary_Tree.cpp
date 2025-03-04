//104. Balanced Binary Tree(easy)
#include <iostream>
#include<vector>
#include<queue>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<map> 
#include<algorithm>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

//------------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* newNode(int val)
{
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}
void printInorder(struct TreeNode* node)
{
    if (node == NULL){
        return;
    }

    // First recur on left child
    printInorder(node->left);
    
    // Then print the data of node
    cout << node->val << " ";

    // Now recur on right child
    printInorder(node->right);
}
//------------------------------------------------------------------
int max_height(struct TreeNode* node,bool &check){
    if (node == NULL){
        return 0;
    }
    int dL=max_height(node->left,check);
    int dR=max_height(node->right,check); 
    if(abs(dL-dR)>1){
        check=false;
    }
    return max(dL,dR)+1;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int max_l=0,max_r=0;
        TreeNode *sub_left,*sub_right;
        bool l_ans=true,r_ans=true;

        sub_left=root->left?root->left:nullptr;
        sub_right=root->right?root->right:nullptr;        

        max_l=sub_left?max_height(sub_left,l_ans):0;
        max_r=sub_right?max_height(sub_right,r_ans):0;

        if(!l_ans || !r_ans){
            return false;
        }
        if(abs(max_l-max_r)<1){
            return false;
        }
        else{
            return true;
        }
    }
};

//---Balanced Binary Tree定義:其中每個節點的兩個子樹的高度差不超過 1。
int main()
{
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
  
    // TreeNode* root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(2);
    // root->left->left = newNode(3);
    // root->right->right = newNode(3);
    // root->left->left->left = newNode(4);
    // root->right->right->right = newNode(4);

    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\n";
    Solution a;
    bool ans=a.isBalanced(root);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;

}