// Unique Binary Search Trees II

#include <bits/stdc++.h>
using namespace std;

/*
Approach (Simple):
- We try every number as root.
- All numbers smaller go to the left subtree.
- All numbers larger go to the right subtree.
- Combine every possible left subtree with every possible right subtree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        // Base case: no numbers → empty tree
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }

        // Try every number as root
        for (int root = start; root <= end; root++) {

            // All possible left subtrees
            vector<TreeNode*> leftTrees = build(start, root - 1);

            // All possible right subtrees
            vector<TreeNode*> rightTrees = build(root + 1, end);

            // Combine left & right
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    trees.push_back(node);
                }
            }
        }

        return trees;
    }
};