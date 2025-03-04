//543. Diameter of Binary Tree
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

// int max_height(struct TreeNode* node){
//     if (node == NULL){
//         return 0;
//     }
//     int dL=max_height(node->left);
//     int dR=max_height(node->right); 
//     return max(dL,dR)+1;
// }
// int BFS_travel(TreeNode* root)
// {
//     // Base Case
//     if (root == NULL || root && !root->left && !root->right){
//         return 0;
//     }
    
//     // Create an empty queue for level order traversal
//     queue<TreeNode*> q;
    
//     int max_l=0,max_r=0,longest=0;
//     TreeNode *sub_left,*sub_right;
//     sub_left=root->left?root->left:nullptr;
//     sub_right=root->right?root->right:nullptr;
//     max_l=sub_left?max_height(sub_left):0;
//     max_r=sub_right?max_height(sub_right):0;
//     longest=max_l+max_r;

//     TreeNode* bigger_node = max_l>max_r?root->left:root->right;
//     // Enqueue Root and initialize height
//     q.push(bigger_node);
    
//     while (q.empty() == false) {
         
//         // Print front of queue and remove it from queue
//         TreeNode* node = q.front();
//         sub_left=node->left?node->left:nullptr;
//         sub_right=node->right?node->right:nullptr;
       
//         max_l=sub_left?max_height(sub_left):0;
//         max_r=sub_right?max_height(sub_right):0;  
//         longest=max(longest,(max_l+max_r));
//         q.pop();
 
//         // Enqueue left child
//         if (node->left != NULL)
//             q.push(node->left);
 
//         // Enqueue right child
//         if (node->right != NULL)
//             q.push(node->right);
//     }

//     return longest;
// }
//---leetcode 101 sol (DFS)
int max_height(struct TreeNode* node,int &dia){
    if (node == NULL){
        return 0;
    }
    int dL=max_height(node->left,dia);
    int dR=max_height(node->right,dia); 
    dia=max(dia,(dL+dR));
    return max(dL,dR)+1;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        max_height(root,dia);
        return dia;
    }
};

int main()
{
    // Let us create binary tree shown in above diagram
   
    TreeNode* root = newNode(3);
    root->left = newNode(1);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    root->left->right = newNode(2);
  
    // TreeNode* root = newNode(1);
    // root->right = newNode(2);


    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\n";
    Solution a;
    int ans=a.diameterOfBinaryTree(root);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;

}