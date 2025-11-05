// ✅ Question: Convert BST to Greater Tree

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

// Definition for a binary tree node.
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
    void solve(TreeNode* root, int &sum) {
        if (!root) return;
        solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        solve(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};

// Utility: Insert node into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Utility: Print inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Example: Create BST [4,2,6,1,3,5,7]
    vector<int> vals = {4,2,6,1,3,5,7};
    TreeNode* root = nullptr;
    for (int val : vals) root = insertBST(root, val);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    Solution sol;
    TreeNode* newRoot = sol.convertBST(root);

    cout << "Greater Tree (Inorder): ";
    inorder(newRoot);
    cout << endl;

    return 0;
}