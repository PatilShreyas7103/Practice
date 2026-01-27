// Range Sum of BST
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
// Approach 1: Inorder Traversal (Brute for BST)
// Idea:
// - Traverse entire tree
// - Add node value if it lies in [low, high]
// - Does NOT use BST property fully
class BruteForce {
public:
    void dfs(TreeNode* root, int &sum, int low, int high) {
        if (!root) return;

        dfs(root->left, sum, low, high);

        if (root->val >= low && root->val <= high)
            sum += root->val;

        dfs(root->right, sum, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        dfs(root, sum, low, high);
        return sum;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(h)   // recursion stack
*/

/*------------------------------------------------------*/
// Approach 2: Optimized using BST Property (BEST)
// Idea:
// - If node value < low → ignore left subtree
// - If node value > high → ignore right subtree
// - Only visit relevant branches
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        // If node value is smaller, go right
        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        // If node value is larger, go left
        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        // Node is within range
        return root->val
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};

/*
Time Complexity:
- Average: O(log n)
- Worst (skewed BST): O(n)

Space Complexity:
- O(h) where h = height of tree
*/