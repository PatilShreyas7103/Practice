// Binary Tree Paths
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*------------------------------------------------------*/
// Approach 1: DFS Recursion (Root to Leaf)
// Idea:
// - Traverse from root to leaf
// - Maintain current path as string
// - When a leaf node is reached, store the path
class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;

        // Add current node value
        path += to_string(root->val);

        // If leaf node, store path
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        // Continue DFS with "->"
        path += "->";
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack, h = tree height
*/

/*------------------------------------------------------*/
// Approach 2: Iterative DFS using Stack (Bonus)
// Idea:
// - Use stack to simulate recursion
// - Store pair of (node, path so far)
// - When leaf is found, push path to answer
class IterativeDFS {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;

        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});

        while (!st.empty()) {
            auto [node, path] = st.top();
            st.pop();

            if (!node->left && !node->right) {
                ans.push_back(path);
            }

            if (node->right) {
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if (node->left) {
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)  // stack storage
*/