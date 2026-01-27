// Sum of Left Leaves
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
// Approach 1: DFS Recursion with Flag (Your Approach)
// Idea:
// - Pass a boolean flag `isLeft`
// - When visiting a node:
//     * if it's a leaf AND isLeft == true → add its value
// - For left child → isLeft = true
// - For right child → isLeft = false
class Solution {
public:
    void dfs(TreeNode* root, int &sum, bool isLeft) {
        if (!root) return;

        // If it's a left leaf
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
            return;
        }

        dfs(root->left, sum, true);
        dfs(root->right, sum, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, false);
        return sum;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(h)   // recursion stack (h = tree height)
*/

/*------------------------------------------------------*/
// Approach 2: Iterative BFS (Bonus)
// Idea:
// - Use queue to traverse tree
// - When a node has a left child that is a leaf → add its value
class BFSApproach {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                if (!node->left->left && !node->left->right) {
                    sum += node->left->val;
                }
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
        return sum;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/