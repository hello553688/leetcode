// C++ program to insert a node
// in a BST
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
 
// Given Node
struct node
{
    int key;
    struct node *left, *right;
};
 
// Function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(
                  sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to insert a new node with
// given key in BST
struct node* insert(struct node* node, int key)
{
     
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);
 
    // Otherwise, recur down the tree
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
 
    // Return the node pointer
    return node;
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;
 
    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
// Function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
 
// Driver Code
int main()
{
     
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    struct node* root = NULL;
 
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Print the BST
    inorder(root);
    
    cout << endl;
    // Key to be found
    int key = 6;
    // Searching in a BST
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;
 
    key = 60;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;
 
    return 0;
}