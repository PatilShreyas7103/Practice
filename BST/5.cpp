// 🌳 Question: Delete Node in a Binary Search Tree (Recursive Solution)
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

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 🧮 Determine the number of children of a node
    int stats(TreeNode* root) {
        if (root->left && root->right)
            return 2;
        else if (!root->left && !root->right)
            return 0;
        else
            return 1;
    }

    // 🌀 Recursive helper to delete the node
    TreeNode* solve(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (root->val == key) {
            int child = stats(root);

            // Case 1: No child
            if (child == 0)
                return NULL;

            // Case 2: One child
            else if (child == 1)
                return (root->left) ? root->left : root->right;

            // Case 3: Two children
            else {
                TreeNode* t = root->right;
                while (t->left)
                    t = t->left; // find inorder successor
                root->val = t->val;
                root->right = solve(root->right, t->val);
                return root;
            }
        }

        // Traverse left or right
        else if (key < root->val)
            root->left = solve(root->left, key);
        else
            root->right = solve(root->right, key);

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        return solve(root, key);
    }
};

// 🔍 Helper function for inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🧠 Driver code (for testing)
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 70;
    root = sol.deleteNode(root, key);

    cout << "Inorder after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}