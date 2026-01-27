// Merge Two Binary Trees
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*------------------------------------------------------*/
// Approach 1: Create a New Merged Tree
// Idea:
// - If both nodes are null → return null
// - If one node exists → clone that node
// - If both exist → create new node with sum of values
// - Recursively merge left and right children
class NewTreeApproach {
public:
    TreeNode* merge(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return nullptr;

        if (p && !q) {
            TreeNode* node = new TreeNode(p->val);
            node->left = merge(p->left, nullptr);
            node->right = merge(p->right, nullptr);
            return node;
        }

        if (!p && q) {
            TreeNode* node = new TreeNode(q->val);
            node->left = merge(nullptr, q->left);
            node->right = merge(nullptr, q->right);
            return node;
        }

        TreeNode* node = new TreeNode(p->val + q->val);
        node->left = merge(p->left, q->left);
        node->right = merge(p->right, q->right);
        return node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)  // new tree + recursion stack
*/

/*------------------------------------------------------*/
// Approach 2: In-place Merge (Interview Preferred)
// Idea:
// - Modify first tree directly
// - If one node is null → return the other
// - If both exist → add values and recurse
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack (h = tree height)
*/