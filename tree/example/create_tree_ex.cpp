#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert nodes in level order
TreeNode* insertLevelOrder(const vector<int*>& arr, int i) {
    if (i >= arr.size() || arr[i] == NULL) return nullptr;

    TreeNode* root = new TreeNode(*arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    return root;
}

// Function to perform inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
#define null nullptr 
int main() {
    // Define the BFS data
    vector<int*> bfsData = {
        new int(3), new int(4), new int(5), new int(1), new int(2), null, null, null, null, new int(0)
    };
    // vector<int> tree1 = {3,4,5,1,2,null,null,null,null,0};
    // Construct the tree
    TreeNode* root = insertLevelOrder(bfsData, 0);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Cleanup
    // Delete the dynamically allocated memory
    for (int* val : bfsData) {
        delete val;
    }
    
    return 0;
}
