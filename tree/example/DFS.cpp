// C++ program for different tree traversals
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

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct Node {
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Given a binary tree, print its nodes in inorder
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left child
    printInorder(node->left);
 
    // Then print the data of node
    cout << node->data << " ";
 
    // Now recur on right child
    printInorder(node->right);
}
 
// Given a binary tree, print its nodes in Preorder
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    
    // Then print the data of node
    cout << node->data << " ";

    // First recur on left child
    printPreorder(node->left);
    
    // Now recur on right child
    printPreorder(node->right);
}

// Given a binary tree, print its nodes in Postorder
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    // First recur on left child
    printPostorder(node->left);
    
    // Now recur on right child
    printPostorder(node->right);

    // Then print the data of node
    cout << node->data << " ";
}

// Driver code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // Function call
    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);
    
    cout << "\n";
    cout << "Preorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\n";
    cout << "Postorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}