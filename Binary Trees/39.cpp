// 1161. Maximum Level Sum of a Binary Tree

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

// Definition for a binary tree node.
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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;             // Level with max sum
        int lev = 1;             // Current level
        long long mx = LONG_MIN; // Track maximum sum

        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;

            for (int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();

                sum += t->val;

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            if (sum > mx) {
                mx = sum;
                ans = lev;
            }
            lev++;
        }

        return ans;
    }
};

// --- Example usage for VS Code ---
TreeNode* createSampleTree() {
    // Example Tree:
    //         1
    //       /   \
    //      7     0
    //     / \
    //    7  -8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;
    cout << "Level with maximum sum: " << sol.maxLevelSum(root) << endl;
    return 0;
}