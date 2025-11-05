// 🌳 Question: Find the minimum depth of a binary tree

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

// 🌿 Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🌱 Recursive helper function
int solve(TreeNode* root) {
    if (!root)
        return 1e9;  // large value to ignore null paths

    if (!root->left && !root->right)
        return 1;  // leaf node → depth = 1

    int leftDepth = solve(root->left);
    int rightDepth = solve(root->right);

    return min(leftDepth, rightDepth) + 1;
}

// 🌴 Main function to find minimum depth
int minDepth(TreeNode* root) {
    if (!root)
        return 0;

    int leftDepth = solve(root->left);
    int rightDepth = solve(root->right);

    // handle cases where one subtree is missing
    if (!root->left)
        return rightDepth + 1;
    if (!root->right)
        return leftDepth + 1;

    return min(leftDepth, rightDepth) + 1;
}

// 🌾 Driver Code (for testing)
int main() {
    /*
           1
          / \
         2   3
        /
       4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << "Minimum Depth of Tree: " << minDepth(root) << endl;

    return 0;
}