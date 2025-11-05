// 🧩 1325. Delete Leaves With a Given Value

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------------- Solution Class ----------------
class Solution {
public:
    TreeNode* solve(TreeNode* root, int t)
    {
        if (!root)
            return NULL;

        root->left = solve(root->left, t);
        root->right = solve(root->right, t);

        if (!root->left && !root->right && root->val == t)
            return NULL;

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        return solve(root, t);
    }
};

// ---------------- Helper Functions ----------------
TreeNode* buildTree(vector<int> nodes) {
    if (nodes.empty()) return NULL;
    vector<TreeNode*> treeNodes(nodes.size(), NULL);

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] != -1)  // use -1 to represent NULL
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

    // Example Tree: [1,2,3,2,-1,2,4]
    // Representation: -1 means NULL
    vector<int> nodes = {1, 2, 3, 2, -1, 2, 4};
    TreeNode* root = buildTree(nodes);

    int target = 2;
    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = sol.removeLeafNodes(root, target);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}