//101. Symmetric Tree (easy)
// see ans:(
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
//leetcode sol:https://leetcode.com/problems/symmetric-tree/solutions/3896468/c-easy-to-read-simple-solution/
class Solution {
public:
    bool is_mirror(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left->val == right->val && is_mirror(left->left, right->right) && is_mirror(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) {
        return is_mirror(root->left, root->right);
    }
};

int main()
{
    vector<int> tree = {1,2,2,null,3,null,3};

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
    bool ans=a.isSymmetric(root);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;

}