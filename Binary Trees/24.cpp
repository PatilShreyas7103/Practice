// 🔹 Question: All Nodes Distance K in Binary Tree

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to store parent of each node in a map
    void solve(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            mp[root->left] = root;
            solve(root->left, mp);
        }
        if (root->right) {
            mp[root->right] = root;
            solve(root->right, mp);
        }
    }

    // Function to return all nodes at distance K from target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> parentMap;
        solve(root, parentMap);

        vector<int> visited(501, 0);
        queue<TreeNode*> q;
        q.push(target);

        while (k--) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                visited[node->val] = 1;

                if (node->left && !visited[node->left->val]) {
                    q.push(node->left);
                }
                if (node->right && !visited[node->right->val]) {
                    q.push(node->right);
                }
                if (parentMap.find(node) != parentMap.end() && !visited[parentMap[node]->val]) {
                    q.push(parentMap[node]);
                }
            }
        }

        // Collect remaining nodes in queue (those at distance K)
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};