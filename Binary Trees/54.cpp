// 🧩 Remove Half Nodes in a Binary Tree
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

// 🌳 Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🧠 Recursive helper function
TreeNode* removeHalfNodes(TreeNode* root) {
    if (!root) return NULL;

    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);

    // If current node has only left child
    if (root->left && !root->right)
        return root->left;

    // If current node has only right child
    if (root->right && !root->left)
        return root->right;

    // If it has both children or no child, keep it
    return root;
}

// ✅ Wrapper function (like Solution::solve)
TreeNode* solve(TreeNode* root) {
    return removeHalfNodes(root);
}

// 🧪 Helper: Inorder traversal to print the final tree
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🧩 Example usage
int main() {
    /*
           1
          / \
         2   3
          \   
           4
          /
         5
       Output tree after removing half nodes:
             1
            / \
           5   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    root = solve(root);

    cout << "Tree after removing half nodes (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}