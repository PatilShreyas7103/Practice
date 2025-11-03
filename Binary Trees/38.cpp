// 129. Sum Root to Leaf Numbers

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
    void solve(TreeNode* root, int ans, int &res)
    {
        if (!root) return;

        // If leaf node → form the full number
        if (!root->left && !root->right) {
            ans = ans * 10 + root->val;   // ✅ FIXED here
            res += ans;
            return;
        }

        solve(root->left, ans * 10 + root->val, res);
        solve(root->right, ans * 10 + root->val, res);
    }

    int sumNumbers(TreeNode* root) {
        int res = 0;
        solve(root, 0, res);
        return res;
    }
};

// --- Example usage for VS Code ---
TreeNode* createSampleTree() {
    // Tree:
    //      1
    //     / \
    //    2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;
    cout << "Sum of all numbers from root to leaf paths = " << sol.sumNumbers(root) << endl;
    return 0;
}