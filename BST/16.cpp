// 🌳 Largest BST in a Binary Tree - Brute Force + Optimal Approaches

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

// ---------------- Tree Node Definition ----------------
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------------- Brute Force Approach ----------------
// Helper function to validate if a tree is a BST
bool isValidBST(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
}

// Count nodes in a subtree
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Main brute-force recursive function
int largestBSTBrute(Node* root) {
    if (!root) return 0;
    if (isValidBST(root, LLONG_MIN, LLONG_MAX)) {
        return countNodes(root);
    }
    return max(largestBSTBrute(root->left), largestBSTBrute(root->right));
}

// ---------------- Optimal Approach ----------------
class Solution {
  public:
    // Custom structure to store information about subtrees
    class treenode {
      public:
        int mn;
        int mx;
        int sz;

        treenode(int m, int n, int s) {
            this->mn = m;
            this->mx = n;
            this->sz = s;
        }
    };

    treenode* solve(Node* root, int &ans) {
        if (root == NULL) {
            // Base: Empty tree is a BST
            return new treenode(INT_MAX, INT_MIN, 0);
        }

        treenode* left = solve(root->left, ans);
        treenode* right = solve(root->right, ans);

        // If current node follows BST property
        if (root->data > left->mx && root->data < right->mn) {
            int size = left->sz + right->sz + 1;
            ans = max(ans, size);
            return new treenode(min(root->data, left->mn), max(root->data, right->mx), size);
        } else {
            // Mark invalid BST
            return new treenode(INT_MIN, INT_MAX, 0);
        }
    }

    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

// ---------------- Main Function (Test) ----------------
int main() {
    /*
              5
             / \
            2   4
           / \
          1   3
    */
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    // Brute Force
    cout << "Brute Force Largest BST Size: " << largestBSTBrute(root) << endl;

    // Optimal
    Solution sol;
    cout << "Optimal Largest BST Size: " << sol.largestBst(root) << endl;

    return 0;
}