// 872. Leaf-Similar Trees

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
    void solve(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;

        solve(root->left, ans);
        if (!root->left && !root->right)
            ans.push_back(root->val);
        solve(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        solve(root1, a);
        solve(root2, b);
        return a == b;
    }
};

// --- Example Usage for VS Code ---
TreeNode* createTree1() {
    // Example Tree 1:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 9  8
    //     / \
    //    7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);
    return root;
}

TreeNode* createTree2() {
    // Example Tree 2:
    //       3
    //      / \
    //     5   1
    //    /   / \
    //   6   7   4
    //          / \
    //         9   8
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(8);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root1 = createTree1();
    TreeNode* root2 = createTree2();

    if (sol.leafSimilar(root1, root2))
        cout << "✅ The two trees are leaf-similar!" << endl;
    else
        cout << "❌ The two trees are not leaf-similar!" << endl;

    return 0;
}