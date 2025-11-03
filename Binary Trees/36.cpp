// 🌲 Root to leaf Path Sum in Binary Tree
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
    bool solve(TreeNode* root, int target, int sum) {
        if (!root)
            return false;

        // If it's a leaf node, check if total sum matches target
        if (!root->left && !root->right) {
            sum += root->val;
            return sum == target;
        }

        // Recurse on left and right
        bool left = solve(root->left, target, sum + root->val);
        bool right = solve(root->right, target, sum + root->val);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};

// --- Helper function to create a sample tree for testing ---
TreeNode* createSampleTree() {
    // Tree:
    //        5
    //       / \
    //      4   8
    //     /   / \
    //    11  13  4
    //   /  \      \
    //  7    2      1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    int targetSum = 22;

    Solution sol;
    cout << "Has Path Sum " << targetSum << "? "
         << (sol.hasPathSum(root, targetSum) ? "Yes ✅" : "No ❌") << endl;

    return 0;
}