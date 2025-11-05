// 🌳 1382. Balance a Binary Search Tree

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
    // Helper: build balanced BST from sorted array
    TreeNode* build(vector<int>& v, int s, int e) {
        if (s > e) return nullptr;
        int mid = (s + e) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = build(v, s, mid - 1);
        node->right = build(v, mid + 1, e);
        return node;
    }

    // Helper: store inorder traversal
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    // Main function to balance BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVals;
        inorder(root, inorderVals);
        return build(inorderVals, 0, inorderVals.size() - 1);
    }
};

// Helper to print inorder traversal of tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
        Example tree:
                1
                 \
                  2
                   \
                    3
                     \
                      4
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* balanced = sol.balanceBST(root);

    cout << "Inorder traversal of balanced BST: ";
    printInorder(balanced);
    cout << endl;

    return 0;
}