// 🧩 LeetCode: House Robber III (for VS Code)

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

// ---------------- TreeNode Definition ----------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------- Solution Class ----------------
class Solution {
public:
    pair<int, int> solve(TreeNode* root)
    {
        if (!root)
            return {0, 0};

        auto l = solve(root->left);
        auto r = solve(root->right);

        int take = root->val + l.second + r.second;
        int dont = max(l.first, l.second) + max(r.first, r.second);

        return {take, dont};
    }

    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};

// ---------------- Helper Functions ----------------
TreeNode* buildTree(vector<int> nodes) {
    if (nodes.empty()) return NULL;
    vector<TreeNode*> treeNodes(nodes.size(), NULL);

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] != -1) // use -1 to represent NULL
            treeNodes[i] = new TreeNode(nodes[i]);
    }

    for (int i = 0, j = 1; j < nodes.size(); i++) {
        if (treeNodes[i]) {
            if (j < nodes.size()) treeNodes[i]->left = treeNodes[j++];
            if (j < nodes.size()) treeNodes[i]->right = treeNodes[j++];
        }
    }
    return treeNodes[0];
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// ---------------- Main Function ----------------
int main() {
    Solution sol;

    // Example Tree: [3,2,3,-1,3,-1,1]
    // (Use -1 to denote NULL)
    vector<int> nodes = {3, 2, 3, -1, 3, -1, 1};
    TreeNode* root = buildTree(nodes);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int ans = sol.rob(root);
    cout << "Maximum amount that can be robbed: " << ans << endl;

    return 0;
}