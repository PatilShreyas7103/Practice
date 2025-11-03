// 🌳 Question: Subtree of Another Tree (LeetCode 572)
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

// ✅ Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ✅ Solution
class Solution {
public:
    // Check if two trees are identical
    bool same(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return same(p->left, q->left) && same(p->right, q->right);
    }

    // DFS traversal to find subtree
    bool solve(TreeNode* root, TreeNode* sub) {
        if (!root) return sub == nullptr;

        if (same(root, sub)) return true;

        return solve(root->left, sub) || solve(root->right, sub);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};

// 🧩 Optional main() for testing
int main() {
    // Example: root = [3,4,5,1,2], subRoot = [4,1,2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    cout << (sol.isSubtree(root, subRoot) ? "✅ Yes, it's a subtree" : "❌ No, it's not a subtree") << endl;
    return 0;
}