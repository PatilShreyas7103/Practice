// 🚀 Question: Vertical Sum of a Binary Tree

#include <bits/stdc++.h>
using namespace std;
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

// 🧩 Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🧮 Function to calculate vertical sums
void solve(TreeNode* root, map<int,int> &mp, int col) {
    if (!root) return;

    // Recur for left and right first
    solve(root->left, mp, col - 1);
    solve(root->right, mp, col + 1);

    // Add current node's value to its vertical column
    mp[col] += root->val;
}

// 🧠 Main function that returns vertical sums as vector
vector<int> verticalSum(TreeNode* root) {
    map<int,int> mp;
    vector<int> ans;

    solve(root, mp, 0);

    for (auto it : mp)
        ans.push_back(it.second);

    return ans;
}

// 🌳 Helper function to build a sample tree
TreeNode* buildSampleTree() {
    /*
          1
         / \
        2   3
       / \   \
      4   5   6

    Vertical columns:
    col -2 → 4
    col -1 → 2
    col  0 → 1 + 5 = 6
    col +1 → 3
    col +2 → 6
    Output → [4, 2, 6, 3, 6]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

// 🧾 Driver code
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = buildSampleTree();

    vector<int> result = verticalSum(root);

    cout << "Vertical sums: ";
    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}