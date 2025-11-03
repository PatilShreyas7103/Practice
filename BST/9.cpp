// 🌳 Question: Lowest Common Ancestor in a BST (Iterative + Recursive)

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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ---------------------------------------------------------
// 🧩 Solution 1: Iterative Approach
// ---------------------------------------------------------
class SolutionIterative {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        int a = p->val;
        int b = q->val;

        while (temp) {
            if (temp->val < a && temp->val < b) {
                temp = temp->right;
            } 
            else if (temp->val > a && temp->val > b) {
                temp = temp->left;
            } 
            else {
                return temp; // LCA found
            }
        }
        return nullptr;
    }
};

// ---------------------------------------------------------
// ⚡ Solution 2: Recursive Approach
// ---------------------------------------------------------
class SolutionRecursive {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        int a = p->val;
        int b = q->val;

        if (root->val < a && root->val < b)
            return solve(root->right, p, q);
        else if (root->val > a && root->val > b)
            return solve(root->left, p, q);
        
        return root; // Found the split point
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};

// ---------------------------------------------------------
// 🧠 Utility Functions
// ---------------------------------------------------------

// Insert node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// ---------------------------------------------------------
// 🧩 Driver Code
// ---------------------------------------------------------
int main() {
    TreeNode* root = nullptr;
    vector<int> values = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for (int val : values) root = insert(root, val);

    cout << "BST (Inorder): ";
    printInorder(root);
    cout << "\n";

    TreeNode* p = root->left;        // Node 2
    TreeNode* q = root->left->right; // Node 4

    SolutionIterative solIter;
    SolutionRecursive solRec;

    TreeNode* ans1 = solIter.lowestCommonAncestor(root, p, q);
    TreeNode* ans2 = solRec.lowestCommonAncestor(root, p, q);

    cout << "Iterative LCA → " << (ans1 ? ans1->val : -1) << "\n";
    cout << "Recursive LCA → " << (ans2 ? ans2->val : -1) << "\n";

    return 0;
}