// 🌳 LeetCode 783: Minimum Distance Between BST Nodes

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
    void solve(TreeNode* root, TreeNode* &prev, int &ans) {
        if (!root) {
            return;
        }

        solve(root->left, prev, ans);

        if (prev) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        solve(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        solve(root, prev, ans);
        return ans;
    }
};

// 🧪 Example usage for local testing
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    cout << "Minimum difference in BST: " << s.minDiffInBST(root) << endl;

    return 0;
}