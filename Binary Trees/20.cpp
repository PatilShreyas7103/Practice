// Lowest Common Ancestor of a Binary Tree

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if (!l)
            return r;
        else if (!r)
            return l;
        else
            return root;
    }
};

int main() {
    // Example test (optional)
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << ans->val << endl;
}