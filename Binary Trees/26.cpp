// ✅ Count Nodes in a Complete Binary Tree

#include <iostream>
#include <cmath>
#include <queue>
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

class Solution {
public:
    int leftHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int rightHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->right;
        }
        return h;
    }

    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh) {
            return (1 << lh) - 1; // If perfect tree, use formula 2^h - 1
        } else {
            return 1 + solve(root->left) + solve(root->right);
        }
    }

    int countNodes(TreeNode* root) {
        return solve(root);
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    /*
            1
           / \
          2   3
         / \  /
        4  5 6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}

// Driver Code
int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;

    cout << "Total nodes in the complete binary tree: " 
         << sol.countNodes(root) << endl;

    return 0;
}