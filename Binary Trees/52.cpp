// 🧩 LeetCode 993: Cousins in Binary Tree

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

// 🌳 Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            bool foundX = false, foundY = false;

            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                // ❌ Check if x and y are siblings
                if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }

                // ✅ Check if found x or y on this level
                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                // Push children for next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // 🎯 Both found on same level and not siblings
            if (foundX && foundY) return true;

            // 🚫 Only one found → not cousins
            if (foundX || foundY) return false;
        }

        return false;
    }
};

// 🧪 Example usage
int main() {
    // Construct binary tree:
    //        1
    //       / \
    //      2   3
    //       \
    //        4
    // and check if 4 and 3 are cousins

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution sol;
    cout << boolalpha << sol.isCousins(root, 4, 3) << endl; // Output: false

    return 0;
}