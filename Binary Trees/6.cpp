// ✅ Question: Maximum Depth of Binary Tree

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Maximum Depth of Tree: " << sol.maxDepth(root) << endl;

    return 0;
}