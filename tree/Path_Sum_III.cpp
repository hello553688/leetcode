//437. Path Sum III(medium)
//see ans :(
//leetcode sol:https://leetcode.com/problems/path-sum-iii/solutions/683906/c-dfs-clean-solution-t-89-m-80/
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
#define null NULL 

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
    int res=0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return res;
        }
        travel_pre(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        // cout<<"res: "<<res<<endl;
        return res;
    }
    void travel_pre(struct TreeNode* node, long long sum){
        if (node == NULL){
            return;
        }
        // cout << node->val << " ";
        if(sum==node->val){
            res++;
        }
        travel_pre(node->left,sum-node->val);
        travel_pre(node->right,sum-node->val);
    }
};
int main()
{
    vector<int> tree = {10,5,-3,3,2,null,11,3,-2,null,1};
    int targetSum=8;

    int cnt = 0;
    queue<TreeNode*> q;
    TreeNode* root = newNode(tree[cnt]);
    cnt++;
    q.push(root);
    //create binary tree
    while (cnt < tree.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (tree[cnt] != NULL) {
            node->left = newNode(tree[cnt]);
            q.push(node->left);
        }
        cnt++;
        if (cnt < tree.size() && tree[cnt] != NULL) {
            node->right = newNode(tree[cnt]);
            q.push(node->right);
        }
        cnt++;
    }

    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\n";
    Solution a;
    int ans=a.pathSum(root,targetSum);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;

}