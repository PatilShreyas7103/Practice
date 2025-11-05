// 🌲 669. Trim a Binary Search Tree

#include <bits/stdc++.h>
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
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // If value < low, discard left subtree
        if (root->val < low)
            return trimBST(root->right, low, high);

        // If value > high, discard right subtree
        if (root->val > high)
            return trimBST(root->left, low, high);

        // Otherwise, recursively fix both sides
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

// Helper function: inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🧪 Example usage
int main() {
    /*
        Example Tree:
              3
             / \
            0   4
             \
              2
             /
            1

        low = 1, high = 3
        Expected trimmed tree (inorder): 1 2 3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    int low = 1, high = 3;
    Solution sol;
    TreeNode* trimmed = sol.trimBST(root, low, high);

    cout << "Inorder traversal after trimming: ";
    inorder(trimmed);
    cout << endl;

    return 0;
}