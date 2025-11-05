// 🌳 Question: Find K-th Ancestor of a Node in a Binary Tree

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

// ----- Tree Node Definition -----
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// ----- Solution Class -----
class Solution {
public:
    bool solve(Node* root, int &k, int node, int &ans) {
        if (!root)
            return false;

        if (root->data == node)
            return true;

        bool left = solve(root->left, k, node, ans);
        bool right = solve(root->right, k, node, ans);

        if (left || right) {
            k--;
            if (k == 0) {
                ans = root->data;
                // Stop further decrements after finding ancestor
                k = INT_MAX;
            }
            return true;
        }
        return false;
    }

    int kthAncestor(Node *root, int k, int node) {
        int ans = -1;
        solve(root, k, node, ans);
        return ans;
    }
};

// ----- Helper Function to Build Tree (for testing) -----
Node* buildTree() {
    /*
        Example Tree:
                 1
                / \
               2   3
              / \
             4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

// ----- Main Function -----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = buildTree();

    Solution sol;
    int k = 2;
    int node = 4;

    int ans = sol.kthAncestor(root, k, node);
    if (ans == -1)
        cout << "No such ancestor exists.\n";
    else
        cout << k << "th ancestor of node " << node << " is: " << ans << "\n";

    return 0;
}