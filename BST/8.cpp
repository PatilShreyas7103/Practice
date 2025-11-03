// 🌳 Question: Validate Binary Search Tree (Two Approaches)

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

// ✅ Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------------------------------------------------
// 🧩 Solution 1: Brute Force (Using Inorder Traversal)
// ---------------------------------------------------------
class SolutionInorder {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);

        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (v[i] >= v[i + 1]) return false;
        }

        return true;
    }
};

// ---------------------------------------------------------
// ⚡ Solution 2: Optimized (Using Range Limits / Recursion)
// ---------------------------------------------------------
class SolutionOptimized {
public:
    bool solve(TreeNode* root, long long mn, long long mx) {
        if (!root) return true;

        if (root->val <= mn || root->val >= mx) return false;

        bool l = solve(root->left, mn, root->val);
        bool r = solve(root->right, root->val, mx);

        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

// ---------------------------------------------------------
// 🧠 Utility Functions
// ---------------------------------------------------------

// Insert into BST for testing
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Print inorder (for verification)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// ---------------------------------------------------------
// 🧩 Driver Code (Test both approaches)
// ---------------------------------------------------------
int main() {
    TreeNode* root = nullptr;

    // Build a valid BST
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) root = insert(root, val);

    cout << "BST (Inorder): ";
    printInorder(root);
    cout << "\n";

    SolutionInorder brute;
    SolutionOptimized opt;

    cout << "Brute Force (Inorder) → " << (brute.isValidBST(root) ? "Valid" : "Invalid") << "\n";
    cout << "Optimized (Range Check) → " << (opt.isValidBST(root) ? "Valid" : "Invalid") << "\n";

    // Create an invalid BST manually
    TreeNode* bad = new TreeNode(5);
    bad->left = new TreeNode(1);
    bad->right = new TreeNode(4);
    bad->right->left = new TreeNode(3);
    bad->right->right = new TreeNode(6);

    cout << "\nInvalid BST (Inorder): ";
    printInorder(bad);
    cout << "\n";

    cout << "Brute Force (Inorder) → " << (brute.isValidBST(bad) ? "Valid" : "Invalid") << "\n";
    cout << "Optimized (Range Check) → " << (opt.isValidBST(bad) ? "Valid" : "Invalid") << "\n";

    return 0;
}