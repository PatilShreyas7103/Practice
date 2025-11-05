// 🧩 Merge Two Binary Trees

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
#include <bits/stdc++.h>
using namespace std;

// 🌳 Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🧠 Recursive helper function to merge trees
TreeNode* mergeTrees(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return NULL;
    else if (p && !q) {
        TreeNode* temp = new TreeNode(p->val);
        temp->left = mergeTrees(p->left, q);
        temp->right = mergeTrees(p->right, q);
        return temp;
    }
    else if (!p && q) {
        TreeNode* temp = new TreeNode(q->val);
        temp->left = mergeTrees(p, q->left);
        temp->right = mergeTrees(p, q->right);
        return temp;
    }
    else {
        TreeNode* temp = new TreeNode(p->val + q->val);
        temp->left = mergeTrees(p->left, q->left);
        temp->right = mergeTrees(p->right, q->right);
        return temp;
    }
}

// ✅ Wrapper function (like Solution::solve)
TreeNode* solve(TreeNode* A, TreeNode* B) {
    return mergeTrees(A, B);
}

// 🧪 Helper: Inorder traversal for output
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🧩 Example usage
int main() {
    /*
       Tree A:         Tree B:
           1               2
          / \             / \
         3   2           1   3
        /                 \   \
       5                   4   7

       Merged Tree:
           3
          / \
         4   5
        / \   \
       5   4   7
    */

    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(3);
    A->right = new TreeNode(2);
    A->left->left = new TreeNode(5);

    TreeNode* B = new TreeNode(2);
    B->left = new TreeNode(1);
    B->right = new TreeNode(3);
    B->left->right = new TreeNode(4);
    B->right->right = new TreeNode(7);

    cout << "Tree A (Inorder): ";
    inorder(A);
    cout << "\nTree B (Inorder): ";
    inorder(B);
    cout << "\n";

    TreeNode* merged = solve(A, B);

    cout << "Merged Tree (Inorder): ";
    inorder(merged);
    cout << "\n";

    return 0;
}