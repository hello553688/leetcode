//104. Maximum Depth of Binary Tree(easy)
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
// Given a binary tree, print its nodes in inorder
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
int search_dep(struct TreeNode* node){
    if (node == NULL){
        return 0;
    }
    // First recur on left child
    int dL=search_dep(node->left);
    int dR=search_dep(node->right);
    cout << node->val << " ";
    cout<<"dL:"<<dL<<endl;
    cout<<"dR:"<<dR<<endl;
    cout<<endl;
    return max(dL,dR)+1;
}

class Solution {
public:
    int maxDepth(TreeNode* root) { 
        int max_dep=0; 
        if(!root){
            return 0;
        }
        max_dep=search_dep(root);
        // dep_l=search_dep(root->left,0);
        // dep_r=search_dep(root->right,0);
        // cout<<"dep_l:"<<dep_l<<endl;
        // cout<<"dep_r:"<<dep_r<<endl;
        
        return max_dep;
    }
};
//leetcode sol
//https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/1770060/c-recursive-dfs-example-dry-run-well-explained/
int main()
{
    // Let us create binary tree shown in above diagram
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    // root->right->right->right = newNode(4);
  
    // TreeNode* root = newNode(1);
    // root->right = newNode(2);


    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\n";
    Solution a;
    int ans=a.maxDepth(root);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;

}