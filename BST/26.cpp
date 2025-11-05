// 🔹 Question: Increasing Order Search Tree (Leetcode 897)

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

// ✅ Optimized Approach (In-place)
class SolutionOptimized {
public:
    void solve(TreeNode* &root, TreeNode* &head) {
        if (!root) return;

        // Right -> Node -> Left (reverse inorder)
        solve(root->right, head);

        root->right = head; // attach next node in sequence
        head = root;        // update head pointer

        solve(root->left, head);

        root->left = nullptr; // make sure left is null
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = nullptr;
        solve(root, head);
        return head;
    }
};

// ✅ Brute Force Approach (using vector)
class SolutionBruteForce {
public:
    vector<int> ans;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* make_tree() {
        if (ans.empty()) return nullptr;
        TreeNode* root = new TreeNode(ans[0]);
        TreeNode* temp = root;
        for (int i = 1; i < ans.size(); i++) {
            temp->right = new TreeNode(ans[i]);
            temp = temp->right;
        }
        return root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return make_tree();
    }
};

// 🧩 Example usage (for testing)
int main() {
    // Constructing a simple BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    // Choose approach
    SolutionOptimized sol; // or SolutionBruteForce sol;
    TreeNode* newRoot = sol.increasingBST(root);

    // Print result
    cout << "Right skewed tree (inorder): ";
    while (newRoot) {
        cout << newRoot->val << " ";
        newRoot = newRoot->right;
    }
    cout << endl;

    return 0;
}