// 🌳 Question: Invert Binary Tree (Iterative BFS + Recursive DFS)
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

// 🌀 Iterative BFS Approach
class Solution_BFS {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Swap left and right children
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return root;
    }
};

// 🌿 Recursive DFS Approach
class Solution_DFS {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // Swap children
        swap(root->left, root->right);

        // Recurse on subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// 🧩 Example main function to test both implementations
int main() {
    // Build sample tree:  4
    //                   /   \
    //                  2     7
    //                 / \   / \
    //                1   3 6   9

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution_BFS sol_bfs;
    Solution_DFS sol_dfs;

    cout << "Inverting using BFS..." << endl;
    TreeNode* inverted1 = sol_bfs.invertTree(root);

    cout << "Inverting using DFS..." << endl;
    TreeNode* inverted2 = sol_dfs.invertTree(inverted1);

    cout << "✅ Tree inverted successfully (both methods executed)" << endl;
    return 0;
}