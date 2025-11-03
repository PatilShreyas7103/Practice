// 🌳 Build Binary Tree from Preorder and Inorder Traversal

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Solution Class
class Solution {
public:
    TreeNode* solve(vector<int>& pre, vector<int>& in, map<int,int> &id, int is, int ie, int ps, int pe) {
        if (ps > pe || is > ie) {
            return NULL;
        }

        TreeNode* node = new TreeNode(pre[ps]);
        int key = id[pre[ps]];
        int cnt = key - is;

        node->left = solve(pre, in, id, is, key - 1, ps + 1, ps + cnt);
        node->right = solve(pre, in, id, key + 1, ie, ps + cnt + 1, pe);

        return node;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int> mp;
        int n = in.size();

        for (int i = 0; i < n; i++) {
            mp[in[i]] = i;
        }

        return solve(pre, in, mp, 0, n - 1, 0, n - 1);
    }
};

// 🌿 Helper function to print tree inorder
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}