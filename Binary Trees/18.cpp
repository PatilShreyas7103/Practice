// 🌳 Question: Symmetric Binary Tree

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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

// Solution class
class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        bool l = solve(p->left, q->right);
        bool r = solve(p->right, q->left);

        if (!l || !r)
            return false;
        if (p->val != q->val)
            return false;

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        if (root->left == nullptr && root->right == nullptr)
            return true;

        return solve(root->left, root->right);
    }
};

// Main function for testing
int main() {
    /*
          1
         / \
        2   2
       / \ / \
      3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);

    if (result)
        cout << "✅ The tree is symmetric." << endl;
    else
        cout << "❌ The tree is not symmetric." << endl;

    return 0;
}