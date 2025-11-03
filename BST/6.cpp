// 🌳 Question: Kth Smallest Element in a BST (Brute Force + Optimized Solutions)

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
// 🧩 Solution 1: Brute Force (Store Inorder Traversal in a Vector)
// ---------------------------------------------------------
class SolutionBruteForce {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        return v[k - 1];
    }
};

// ---------------------------------------------------------
// ⚡ Solution 2: Optimized (Use Counter Variable & Early Stop)
// ---------------------------------------------------------
class SolutionOptimizedCount {
public:
    void inorder(TreeNode* root, int& cnt, int& ans, int k) {
        if (!root) return;

        inorder(root->left, cnt, ans, k);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return; // Stop traversal once found
        }
        inorder(root->right, cnt, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, cnt = 0;
        inorder(root, cnt, ans, k);
        return ans;
    }
};

// ---------------------------------------------------------
// 🚀 Solution 3: Optimized (Using Decrementing K Technique)
// ---------------------------------------------------------
class SolutionOptimizedDecrement {
public:
    void inorder(TreeNode* root, int& ans, int& k) {
        if (!root) return;

        inorder(root->left, ans, k);
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }
        inorder(root->right, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root, ans, k);
        return ans;
    }
};

// ---------------------------------------------------------
// 🧠 Utility Functions
// ---------------------------------------------------------

// Build a simple BST for testing
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Inorder print (for verification)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// ---------------------------------------------------------
// 🧩 Driver Code (Test all 3 approaches)
// ---------------------------------------------------------
int main() {
    TreeNode* root = nullptr;
    vector<int> values = {5, 3, 6, 2, 4, 1};
    for (int val : values) root = insert(root, val);

    cout << "BST (Inorder): ";
    printInorder(root);
    cout << "\n";

    int k = 3;

    SolutionBruteForce brute;
    SolutionOptimizedCount optCount;
    SolutionOptimizedDecrement optDec;

    cout << "Brute Force → " << brute.kthSmallest(root, k) << "\n";
    cout << "Optimized (Count) → " << optCount.kthSmallest(root, k) << "\n";
    cout << "Optimized (Decrement) → " << optDec.kthSmallest(root, k) << "\n";

    return 0;
}