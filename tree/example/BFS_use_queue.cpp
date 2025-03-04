// C++ program to print level order traversal
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
 
// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};
 
// Iterative method to find height of Binary Tree
void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    
    //1->print and pop 1,get 2,3->print and pop 2,get 4,5->print and pop 3,4,5
    //queue state:1->2,3->3,4,5
    while (q.empty() == false) {
         
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        // Enqueue left child
        if (node->left != NULL)
            q.push(node->left);
 
        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
    }
}
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}