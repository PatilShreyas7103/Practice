// ✅ Question: Same Tree

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
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
    bool solve(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        bool leftSame = solve(p->left, q->left);
        bool rightSame = solve(p->right, q->right);

        return (leftSame && rightSame && p->val == q->val);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};

// Example usage
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "Both trees are identical." : "Trees are different.") << endl;

    return 0;
}