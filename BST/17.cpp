// 🌳 Convert Sorted Array to Binary Search Tree

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ✅ Solution Class
class Solution {
public:
    // Helper function to recursively build the BST
    TreeNode* solve(int i, int j, vector<int> &v) {
        if (i > j) return NULL;

        int mid = (i + j) / 2;
        TreeNode* node = new TreeNode(v[mid]);

        node->left = solve(i, mid - 1, v);
        node->right = solve(mid + 1, j, v);

        return node;
    }

    // Main function
    TreeNode* sortedArrayToBST(vector<int>& v) {
        return solve(0, v.size() - 1, v);
    }
};

// Utility function for inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Driver Code
int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}