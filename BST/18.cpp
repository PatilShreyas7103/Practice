// 🌳 Minimum Absolute Difference in BST

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
    TreeNode* prev = NULL;
    
    void inorder(TreeNode* root, int &ans) {
        if (!root) return;

        inorder(root->left, ans);
        if (prev) {
            ans = min(ans, abs(root->val - prev->val));
        }
        prev = root;
        inorder(root->right, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        inorder(root, ans);
        return ans;
    }
};

// --- Helper function to create a simple BST for testing ---
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

int main() {
    // Example BST: [4, 2, 6, 1, 3]
    TreeNode* root = NULL;
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 6);
    root = insertBST(root, 1);
    root = insertBST(root, 3);

    Solution sol;
    cout << "Minimum Absolute Difference: " << sol.getMinimumDifference(root) << endl;

    return 0;
}